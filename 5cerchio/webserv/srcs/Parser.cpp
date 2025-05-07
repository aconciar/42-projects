/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp   		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:45:15 by ucolla            #+#    #+#             */
/*   Updated: 2025/02/05 16:25:54 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "ConfigError.hpp"

void Parser::parseRouteLine(const std::string& line, Router &location) {
	std::string directive, key;
	directive = trimLine(line);
		
	std::istringstream stream(directive);
	stream >> key;

	if (key == "allowed_methods")
	{
		std::string method;
		while (stream >> method) {
			if (method != "POST" && method != "GET" && method != "DELETE")
				throw MethodError(method, parsingCounter);
			location.getAllowedMethods().push_back(method);
		}
		isEmpty(key, method, "");
		invalidKeyword(stream);
	}
	else if (key == "redirect")
	{
		if (!(stream >> location.getRedirect().status_code))
			throw ConfigFileError("Invalid or missing status code",
									parsingCounter);								
		if (!(stream >> location.getRedirect().path))
			throw ConfigFileError("Invalid or missing redirection path",
									parsingCounter);		
		invalidKeyword(stream);
	}
	else if (key == "root")
	{
		std::string root;
		stream >> root;
		isEmpty(key, root, "");
		location.setRoot(root);
		invalidKeyword(stream);
	}
	else if (key == "alias")
	{
		std::string alias;
		stream >> alias;
		isEmpty(key, alias, "");
		location.setAlias(alias);
		invalidKeyword(stream);
		aliasWarning(location, parsingCounter);
	}
	else if (key == "directory_listing")
	{
		std::string str;
		stream >> str;
		isEmpty(key, str, "");
		location.setDirectoryListing(str == "on");
		invalidKeyword(stream);
	}
	else if (key == "default_file")
	{
		std::string defaultFile;
		stream >> defaultFile;
		isEmpty(key, defaultFile, "");
		location.setDefaultFile(defaultFile);
		invalidKeyword(stream);
	}
	else if (key == "cgi_extension")
	{
		std::string str;
		while (stream >> str) {
			if (str != ".py" && str != "py" &&
				str != ".sh" && str != "sh")
				throw ConfigFileError("Unsupported CGI extension " + str, parsingCounter);
			location.getCgiExtensions().push_back(str);
		}
		isEmpty(key, str, "");
		invalidKeyword(stream);
	}
	else if (key == "cgi_path")
	{
		std::string cgiPath;
		stream >> cgiPath;
		isEmpty(key, cgiPath, "");
		location.setCgiPath(cgiPath);
		invalidKeyword(stream);
	}
	else if (key == "upload_dir")
	{
		std::string uploadDir;
		stream >> uploadDir;
		isEmpty(key, uploadDir, "");
		location.setUploadDir(uploadDir);
		invalidKeyword(stream);
	}
	else if (key == "location")
		throw ConfigFileError("Unclosed location block", parsingCounter - 1);
	else
	{
		if (hasAlpha(line))
			throw InvalidKeywordError(key, parsingCounter);
	}
}

void Parser::routeParser(Router &location) {
	std::string line;

	while (std::getline(_file, line)) {
		parsingCounter++;
		if (line.find('#') != std::string::npos)
		{
			line = line.substr(0, line.find('#') - 1);
			if (!hasAlpha(line))
				continue;
		}
		if (line.empty() || !hasAlpha(line))
			continue;

		if (checkClosingBracket(line))
		{
			if (line.find("location") != std::string::npos)
				throw ConfigFileError("Unclosed location block", parsingCounter - 1);
			break;
		}
		parseRouteLine(line, location);
	}
}

void Parser::parseServerLine(const std::string& line, ServerConfig& server) {
	std::string directive, key;
	directive = trimLine(line);
		
	std::istringstream stream(directive);
	stream >> key;

	if (key == "listen")
	{
		std::string hostPort;
		stream >> hostPort;

		std::string host;
		int port;
		size_t column = hostPort.find(':');
		if (column == std::string::npos)
			throw InvalidKeywordError("Missing column or empty field in listen directive", parsingCounter);

		host = hostPort.substr(0, column);
		server.setHost(host);
		if (server.getHost() == "")
			throw ConfigFileError("Missing host in server block", parsingCounter);
		port = std::atoi((hostPort.substr(column + 1, hostPort.size() - column)).c_str());
		if (port < 1024 || port > 65535)
			throw PortError("Invalid port: " + hostPort.substr(column + 1, hostPort.size() - column), parsingCounter);								// PORT ERROR
		server.setPort(port);
		invalidKeyword(stream);
	}
	else if (key == "allowed_methods")
	{
		std::string method;
		while (stream >> method) {
			if (method != "POST" && method != "GET" && method != "DELETE")
				throw MethodError(method, parsingCounter);
			server.getAllowedMethods().push_back(method);
		}
		isEmpty(key, method, "");
		invalidKeyword(stream);
	}
	else if (key == "error_page") {
		std::string path;
		int			status_code;

		if (!(stream >> status_code) || status_code < 400 || status_code > 504)
			throw ConfigFileError("Missing status code or invalid value", parsingCounter);
		if (!(stream >> path) || path == "")
			throw ConfigFileError("Missing path to error page", parsingCounter);
		server.setErrorPage(status_code, path);
		invalidKeyword(stream);
	}
	else if (key == "server_name")
	{
		std::string name;
		while (stream >> name)
			server.getServerNames().push_back(name);
		isEmpty(key, name, "");
		invalidKeyword(stream);
	}
	else if (key == "root")
	{
		std::string value;
		stream >> value;
		isEmpty(key, value, "");
		server.setRoot(value);
		invalidKeyword(stream);
	}
	else if (key == "directory_listing")
	{
		std::string str;
		stream >> str;
		isEmpty(key, str, "");
		server.setDirectoryListing(str == "on");
		invalidKeyword(stream);
	}
	else if (key == "client_max_body_size")
	{
		std::string client_max_body_size;
		stream >> client_max_body_size;
		isEmpty(key, client_max_body_size, "");
		parseClientMaxBodySize(client_max_body_size, server);
		invalidKeyword(stream);
	}
	else if (key == "default_file")
	{
		std::string defaultFile;
		stream >> defaultFile;
		isEmpty(key, defaultFile, "");
		server.setDefaultFile(defaultFile);
		invalidKeyword(stream);
	}
	else if (key == "location")
	{
		Router location(server.getRoot(), &server);
		std::string path;

		location.setDefaultServerRoot(server.getRoot());
		checkAfterBracket(line, '{');
		stream >> path;

		if (path == "{")
			throw LocationBlockError("Missing location path", parsingCounter);
		
		size_t last_bracket = path.find_last_of('{');
		if (last_bracket != std::string::npos)
			path = path.substr(0, last_bracket);
		else
		{
			std::string bracket;
			stream >> bracket;
			if (bracket != "{")
				throw LocationBlockError("Invalid keyword '" + bracket + "'", parsingCounter);
		}

		location.setPath(path);
		routeParser(location);
		server.getAllLocations().push_back(location);
	}
	else if (key == "upload_dir")
	{
		std::string value;
		stream >> value;
		isEmpty(key, value, "");
		server.setUploadPath(value);
		invalidKeyword(stream);
	}
	else if (key == "server")
		throw ConfigFileError("Unclosed server block", parsingCounter - 1);
	else
	{
		if (hasAlpha(line))
			throw InvalidKeywordError(key, parsingCounter);
	}
}

ServerConfig Parser::parseServerBlock(int counter) {
	ServerConfig 	server(counter);
	std::string 	line;
	int				server_block_end = 0;
	
	while (std::getline(_file, line)) {
		parsingCounter++;
		if (line.find('#') == 0)
			continue;
			
		if (line.find('#') != std::string::npos)
		{
			line = line.substr(0, line.find('#') - 1);
			if (!hasAlpha(line))
				continue;
		}

		if (line.empty() || !hasAlpha(line))
			continue;

		if (checkClosingBracket(line))
		{
			if (line.find("server") != std::string::npos)
				throw ConfigFileError("Unclosed server block", parsingCounter - 1);
			server_block_end = 1;
			break;
		}
		parseServerLine(line, server);
	}
	if (server_block_end == 0)
		throw ConfigFileError("Unclosed server block", parsingCounter - 1);
	if (server.getRoot() == "")
		throw ConfigFileError("Missing root in server block", 0);
	if (server.getHost() == "" || server.getPort() == 0)
		throw ConfigFileError("Invalid or empty 'listen' directive", 0);
	return server;
}

bool Parser::parseConfigFile(const std::string &configFile) {
	_file.open(configFile.c_str());
    if (!_file.is_open())
	{
		_file.close();
		throw ConfigFileError("Cannot open file", 0);
	}

	checkEmptyFile(_file);
	parsingCounter = 1;
	_file.seekg(0);

	std::string line;
	while (std::getline(_file, line)) {
		if (line.find('#') == 0)
		{
			parsingCounter++;
			continue;
		}
		if (line.find("server") != std::string::npos)
		{
			checkServerLine(line);
			size_t bracket = line.find_last_of('{');
			if (bracket == std::string::npos)
				throw ConfigFileError("Missing opening bracket ", parsingCounter);

			checkAfterBracket(line, '{');
			_serverConfigs.push_back(parseServerBlock(parsingCounter));
		}
		parsingCounter++;
	}
	_file.close();
	return true;
}

int serverFinder(std::vector<Server*> &servers, int port, std::string host) {
	int index = 0;
	for (std::vector<Server*>::iterator it = servers.begin(); it != servers.end(); ++it) {
		if ((*it)->getServerDefaultConfig()->getHost() == host &&
			(*it)->getServerDefaultConfig()->getPort() == port)
		{
			return index;
		}
		index++;
	}
	return -1;
}

void	Parser::populateServerConfigs(ServerManager &manager)
{
	if (_serverConfigs.empty())
		return ;

	for (std::vector<ServerConfig>::iterator it = _serverConfigs.begin(); it != _serverConfigs.end(); ++it) {
		int	port = it->getPort();
		std::string host = it->getHost();
		int isSet = serverFinder(manager.getServers(), port, host);
		
		if (isSet < 0)
		{
			std::cout << YELLOW
					<< "Server listening on HOST:PORT "
					<< it->getHost()
					<< ":"
					<< it->getPort()
					<< RESET
					<< std::endl;
			ServerConfig configCopy = *it;
			manager.addServer(new Server(configCopy));
		}
		else
		{
			if (it->getServerNames().empty())
			{
				std::cout << PURPLE << "[ WARNING ]\n" << RESET << "You are trying to create a server for "
						<< YELLOW << it->getHost() << ":" << it->getPort() << RESET
						<< " with no server_name specified, at" << " line: " << YELLOW << it->_counter << RESET << ".\n"
						<< "It won't be served because a default server block already exists for this HOST:PORT.\n"
						<< "You need to specify a server_name for that block or delete the block.\n"
						<< "The server will keep running anyway.\n";
			}
			else
			{
				for (size_t i = 0; i < it->getServerNames().size(); i++) {
					ServerConfig configCopy = *it;
					manager.getServers()[isSet]->addServerConfig(configCopy, it->getServerNames()[i]);
				}
			}
		}
	}
	_serverConfigs.clear();
}
