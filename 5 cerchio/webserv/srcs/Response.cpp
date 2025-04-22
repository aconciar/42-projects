/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:49:18 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/17 17:01:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"
#include "Client.hpp"

bool	Response::sendResponse(const std::string &message)
{
	srand(time(0));
	std::ostringstream	response;
	
	std::cout << YELLOW << "RESPONSE -- " << "HTTP/1.1 " << status_code << " " << message << RESET << "\n\n";
	
	response << "HTTP/1.1 " << status_code << " " << message << "\r\n";
	if (!redirect_path.empty() && (status_code >= 300 && status_code < 400))
		response << "Location: " << redirect_path << "\r\n";
	response << "Content-Length: " << body.size() << "\r\n"
				<< "Content-Type: " << mimeType << "\r\n";

	/* SESSION COOKIES */
	// response << "Set-Cookie: SESSIONID=" << std::hex << rand() << "; HttpOnly; Path=/; Max-Age=3600";
	// std::cout << "Set-Cookie: SESSIONID=" << std::hex << rand() << "; HttpOnly; Path=/; Max-Age=3600\n";

	if (connection == "keep-alive" &&
		status_code != 301 && status_code != 302 && status_code != 303 &&
		status_code != 307 && status_code != 308 &&
		status_code != 408 && status_code != 411 &&
		status_code != 414 && status_code != 431 &&
		status_code != 500 && status_code != 501 && status_code != 502 &&
		status_code != 503 && status_code != 504)
	{
		response << "Connection: keep-alive\r\n";
	}
	else
	{
		response << "Connection: close\r\n";
		connection = "close";
	}
	response << "\r\n" << body;
	std::string	responseStr = response.str();
	if (send(fd, responseStr.c_str(), responseStr.size(), 0) == -1)
	{
		perror("send");
		return (false);
	}
	if (connection == "close")
		return (false);
	return (true);
}

bool	Response::sendErrorResponse(int code, const std::string &message, ServerConfig *config)
{
	std::string			error_page_path;
	std::ifstream 		page;
	std::ostringstream	oss;

	oss << code;
	if (config && config->getAllErrorPages().size() != 0)
	{
		error_page_path = config->getErrorPage(code);
		if (error_page_path != "")
		{
			page.open(error_page_path.c_str());
			if (page.is_open())
			{
				std::string line;
				while(getline(page, line))
				{
					body += line;
				}
				if (VERBOSE_MODE == 1)
					std::cout << "Sending custom error page as response\n";
			}
			else
				body = "<h1>" + oss.str() + " " + message + "</h1>";
		}
		else
			body = "<h1>" + oss.str() + " " + message + "</h1>";
	}
	else
		body = "<h1>" + oss.str() + " " + message + "</h1>";

	status_code = code;
	mimeType = "text/html";
	sendResponse(message);
	return (false);
}

bool	Response::handleFileRequest(const std::string &path)
{
	body = readFileContent(path);
	if (body.empty())
		return (false);
	setMimeType(path);
	sendResponse("OK");
	return (true);
}

bool	Response::handleGetRequest(Request &req, IConfig *configFile, Client *client, fd_set *master_read_set, int &max_fd)
{
	if (!isAllowed(req.getMethod(), configFile->getAllowedMethods()))
		return (sendErrorResponse(405, "Method not allowed", _defaultConfig));
		
	if (req.getHeader("Connection") == "keep-alive")
		connection = "keep-alive";

	if (configFile->getRedirect().path != "")
	{
		if (VERBOSE_MODE == 1)
			std::cout << "REDIRECT: " << redirect_path << std::endl;
		redirect_path = configFile->getRedirect().path;
		return (sendErrorResponse(configFile->getRedirect().status_code, "Moved Permanently", _defaultConfig));
	}
	
	std::string request_path = req.getPath();
	std::string config_path = configFile->getPath();
	
	std::string	path;
	if (request_path == config_path ||
		(request_path.find(config_path) == 0 && !config_path.empty()))
	{
		if (VERBOSE_MODE == 1)
			std::cout << "PERFECT OR PARTIAL MATCH\n";
		if (configFile->getAlias() != "")
		{
			std::string trailingRequestPath = request_path.substr(config_path.size());
			path = configFile->getAlias() + trailingRequestPath;
		}
		else
		{
			if (configFile->getRoot() == "")
				path = _defaultConfig->getDefaultServerRoot() + request_path;
			else
				path = configFile->getRoot() + request_path;
		}
	}
	else
	{	
		if (VERBOSE_MODE == 1)
			std::cout << "DEFAULT ROOT\n";
		path = configFile->getRoot() + request_path;
	}
	
	if (VERBOSE_MODE == 1)
		std::cout << "PATH --> " << path << std::endl;

	if (!isDirectory(path))
	{
		if (isCgiFile(path, configFile))
		{
			pid_t cgiPid = -1;
			int cgiFd = -1;
			bool ok = handleCgiRequest(req, path, cgiPid, cgiFd, configFile);
			if (!ok)
				return (sendErrorResponse(500, "Internal Server Error", _defaultConfig));
			client->setCgi(true);
			client->setCgiFd(cgiFd);
			client->setCgiPid(cgiPid);
			client->setCgiStart(time(NULL));
			client->clearCgiBuffer();

			FD_SET(cgiFd, master_read_set);
			if (cgiFd > max_fd)
				max_fd = cgiFd;
			return (true);
		}
		else
		{
			if (!handleFileRequest(path))
				return (sendErrorResponse(404, "Not Found", _defaultConfig));
		}
		return true;
	}

	if (path[path.size() - 1] != '/' && req.getPath() != "/")
	{
		redirect_path = req.getPath() + "/";
		if (VERBOSE_MODE == 1)
		{
			std::cout << "Added trailing slash to "
				<< req.getPath()
				<< ", redirecting to --> "
				<< redirect_path
				<< std::endl;
		}
		return (sendErrorResponse(301, "Moved Permanently", _defaultConfig));
	}

	std::string indexFile;
	if (isCgiFile(path, configFile))
	{
		int cgiPid = -1;
		int cgiFd = -1;
		bool ok = handleCgiRequest(req, path, cgiPid, cgiFd, configFile);
		if (!ok)
			return (sendErrorResponse(500, "Internal Server Error", _defaultConfig));
		client->setCgi(true);
		client->setCgiFd(cgiFd);
		client->setCgiPid(cgiPid);
		client->setCgiStart(time(NULL));
		client->clearCgiBuffer();

		FD_SET(cgiFd, master_read_set);
		if (cgiFd > max_fd)
			max_fd = cgiFd;
		return (true);
	}
	else if (configFile->getDefaultFile() != "")
		indexFile = path + configFile->getDefaultFile();
	else
	{
		if (configFile->getDirectoryListing() == true)
			return generateAutoIndex(req, path);
		else
			return (sendErrorResponse(404, "Not Found", _defaultConfig));
	}

	if (!handleFileRequest(indexFile))
		return (sendErrorResponse(404, "Not Found", _defaultConfig));
	return true;
} 

bool Response::handlePostRequest(Request &req, IConfig *configFile, Client *client, fd_set *master_read_set, int &max_fd)
{
	std::string filename;
	std::string fileContent;

	if (req.getHeader("Connection") == "keep-alive")
		connection = "keep-alive";
	if (!isAllowed(req.getMethod(), configFile->getAllowedMethods()))
		return (sendErrorResponse(405, "Method not allowed", _defaultConfig));

	std::string request_path = req.getPath();
    std::string config_path  = configFile->getPath();
    std::string path;

    if (request_path == config_path ||
        (request_path.find(config_path) == 0 && !config_path.empty()))
    {
        if (configFile->getAlias() != "")
        {
            std::string trailing = request_path.substr(config_path.size());
            path = configFile->getAlias() + trailing;
        }
        else
            path = configFile->getRoot() + request_path;
    }
    else
        path = configFile->getRoot() + request_path;

    if (!isCgiFile(path, configFile))
        return sendErrorResponse(404, "Not Found - No CGI configured", _defaultConfig);

    pid_t cgiPid = -1;
    int cgiFd    = -1;
    bool ok = handleCgiRequest(req, path, cgiPid, cgiFd, configFile);
    if (!ok)
        return sendErrorResponse(500, "Internal Server Error", _defaultConfig);

    client->setCgi(true);
    client->setCgiFd(cgiFd);
    client->setCgiPid(cgiPid);
    client->setCgiStart(time(NULL));
    client->clearCgiBuffer();

    FD_SET(cgiFd, master_read_set);
    if (cgiFd > max_fd)
        max_fd = cgiFd;

    return true;
}

bool Response::handleDeleteRequest(Request &req, IConfig *configFile, Client *client, fd_set *master_read_set, int &max_fd)
{
	if (req.getHeader("Connection") == "keep-alive")
		connection = "keep-alive";
	if (!isAllowed(req.getMethod(), configFile->getAllowedMethods()))
		return (sendErrorResponse(405, "Method not allowed", _defaultConfig));

    std::string request_path = req.getPath();
    std::string config_path  = configFile->getPath();
    std::string path;
    if (request_path == config_path ||
        (request_path.find(config_path) == 0 && !config_path.empty()))
    {
        if (configFile->getAlias() != "")
        {
            std::string trailing = request_path.substr(config_path.size());
            path = configFile->getAlias() + trailing;
        }
        else
            path = configFile->getRoot() + request_path;
    }
    else
        path = configFile->getRoot() + request_path;

    if (!isCgiFile(path, configFile))
        return (sendErrorResponse(404, "Not Found - No CGI configured", _defaultConfig));
		
    pid_t cgiPid = -1;
    int cgiFd    = -1;
    bool ok = handleCgiRequest(req, path, cgiPid, cgiFd, configFile);
    if (!ok)
        return (sendErrorResponse(500, "Internal Server Error", _defaultConfig));

    client->setCgi(true);
    client->setCgiFd(cgiFd);
    client->setCgiPid(cgiPid);
    client->setCgiStart(time(NULL));
    client->clearCgiBuffer();

    FD_SET(cgiFd, master_read_set);
    if (cgiFd > max_fd)
        max_fd = cgiFd;

    return (true);
}
