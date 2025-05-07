/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:20:37 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/17 17:13:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"

bool	Response::isAllowed(std::string &req_method, std::vector<std::string> &allowed_methods)
{
	if (allowed_methods.empty())	
		return true;
	for (std::vector<std::string>::iterator it = allowed_methods.begin(); it != allowed_methods.end(); it++)
	{
		if (*it == req_method)
			return true;
	}
	return false;
}

void	Response::setMimeType(const std::string &path)
{
	size_t dotPos = path.find_last_of('.');
	if (dotPos != std::string::npos)
	{
		std::string extension = path.substr(dotPos);
		if (extension == ".html" || extension == ".htm")
			mimeType = "text/html";
		if (extension == ".css")
			mimeType = "text/css";
		if (extension == ".js")
			mimeType = "application/javascript";
		if (extension == ".jpg" || extension == ".jpeg")
			mimeType = "image/jpeg";
		if (extension == ".png")
			mimeType = "image/png";
		if (extension == ".gif")
			mimeType = "image/gif";
		if (extension == ".txt")
			mimeType = "text/plain";
		if (extension == ".json")
			mimeType = "application/json";
		if (extension == ".xml")
			mimeType = "application/xml";
		if (extension == ".pdf")
			mimeType = "application/pdf";
	}
}

std::string Response::readFileContent(const std::string &path)
{
	std::ifstream	file(path.c_str(), std::ios::binary);

	if (access(path.c_str(), R_OK) != 0)
		return ("");
	if (!file.is_open())
		return ("");
	std::ostringstream	fileContent;
	fileContent << file.rdbuf();
	file.close();
	return (fileContent.str());
}

bool	Response::isDirectory(const std::string &path)
{
	struct stat	statBuffer;

	if (stat(path.c_str(), &statBuffer) == 0)
	{
		if (S_ISDIR(statBuffer.st_mode))
			return (true);
	}
	else
		std::cerr << RED << "Error in stat(" << path << "): " << strerror(errno) << RESET << std::endl;
	return (false);
}

bool	Response::generateAutoIndex(Request &req, const std::string &path)
{
	std::ostringstream html;
	status_code = 200;
	mimeType = "text/html";
	
	html << "<html><head><title>Index of " << req.getPath() << "</title></head>\n";
    html << "<body><h1>Index of " << req.getPath() << "</h1><hr><pre>\n";
	
	DIR* dir = opendir(path.c_str());
	if (dir) {
		struct dirent* entry;
		struct stat file_stat;
		
		while ((entry = readdir(dir)) != NULL) {
			
			std::string full_path = path;
			if (full_path[full_path.size() - 1] != '/' && full_path != "/")
				full_path += "/";
			full_path += entry->d_name;
			
            if (stat(full_path.c_str(), &file_stat) == 0) {
                std::string type = S_ISDIR(file_stat.st_mode) ? "[DIR]" : "[FILE]";
                
				std::ostringstream ss;
				ss << (file_stat.st_size / 1024) << "KB";
				
                std::string size = S_ISDIR(file_stat.st_mode) ? "" : ss.str();

                char time_str[100];
                strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M", 
                        localtime(&file_stat.st_mtime));

				std::string reqPath;
				req.getPath()[req.getPath().size() - 1] != '/'?
						reqPath = req.getPath() + "/" :
						reqPath = req.getPath();
                
                html << type << " "
                     << "<a href=\"" << reqPath + entry->d_name 
                     << (S_ISDIR(file_stat.st_mode) ? "/" : "") << "\">" 
                     << entry->d_name << "</a> "
                     << size << " "
                     << time_str << "\n";
            }
		}
		closedir(dir);
	}

	body = html.str();
	return sendResponse("OK");
}

bool Response::saveUploadedFile(const std::string &filename, const std::string &fileContent, std::string &uploadPath)
{
	if (uploadPath.empty())
	{
		if (VERBOSE_MODE == 1)
			std::cerr << RED << "No upload path specified\n" << RESET << "Using default upload path" << std::endl;
		uploadPath = "./upload/";
	}
	std::string fullPath = uploadPath + filename;
	if (access(uploadPath.c_str(), F_OK) != 0)
	{
		if (mkdir(uploadPath.c_str(), 0777))
			return (false);
	}
	std::ofstream outFile(fullPath.c_str(), std::ios::binary);
	if (!outFile)
	{
		std::cerr << RED << "Cannot open file " << RESET << fullPath << std::endl;
		return (false);
	}
	outFile.write(fileContent.c_str(), fileContent.size());
	outFile.close();
	return (true);
}

std::string Response::extractBoundary(const std::string &contentType)
{
	size_t pos = contentType.find("boundary=");
	if (pos == std::string::npos)
		return "";
	return contentType.substr(pos + 9);
}

bool Response::extractFileData(const std::string &body, const std::string &boundary, std::string &filename, std::string &fileContent)
{
	size_t filenamePos = body.find("filename=");
	if (filenamePos == std::string::npos)
		return (false);

	size_t startFilename = filenamePos + 10;
	size_t endFilename = body.find("\"", startFilename);
	filename = body.substr(startFilename, endFilename - startFilename);
	
	size_t fileDataStart = body.find("\r\n\r\n", endFilename) + 4;
	size_t fileDataEnd = body.find("--" + boundary, fileDataStart) - 2;
	
	if (fileDataStart == std::string::npos || fileDataEnd == std::string::npos)
		return (false);
	fileContent = body.substr(fileDataStart, fileDataEnd - fileDataStart);
	return (true);
}

