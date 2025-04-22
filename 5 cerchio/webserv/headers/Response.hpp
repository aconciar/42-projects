/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:03:07 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/17 17:59:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "Common.hpp"
#include "Request.hpp"
#include "ServerConfig.hpp"
#include "Client.hpp"

class Request;

class Response {
	
	private:
		int				status_code;
		int				fd;
		std::string		mimeType;
		std::string		body;
		std::string	 	connection;
		std::string		redirect_path;
		std::string		cgi_extension;
		ServerConfig 	*_defaultConfig;

	public:
		Response() : 
			status_code(200),
			fd(0),
			mimeType("text/html"),
			connection("close"),
			redirect_path(""),
			cgi_extension(""),
			_defaultConfig(NULL) {}
		Response(int fd, ServerConfig *defaultConfig) :
			status_code(200),
			fd(fd),
			mimeType("text/html"),
			connection("close"),
			redirect_path(""),
			cgi_extension(""),
			_defaultConfig(defaultConfig) {}
		~Response() {}

		/* ResponseUtils.cpp */
		bool			isAllowed(std::string &req_method, std::vector<std::string> &allowed_methods);
		void			setMimeType(const std::string &path);
		std::string		readFileContent(const std::string &path);
		bool			isDirectory(const std::string &path);
		bool			generateAutoIndex(Request &req, const std::string &path);
		bool			saveUploadedFile(const std::string &filename, const std::string &fileContent, std::string &uploadPath);
		std::string		extractBoundary(const std::string &contentType);
		bool			extractFileData(const std::string &body, const std::string &boundary, std::string &filename, std::string &fileContent);
		
		/* Response.cpp */
		bool			sendResponse(const std::string &message);
		bool			sendErrorResponse(int code, const std::string &message, ServerConfig *defaultConfig);
		bool			handleFileRequest(const std::string &path);
		bool			handleGetRequest(Request &req, IConfig *configFile, Client *client, fd_set *master_read_set, int &max_fd);
		bool			handlePostRequest(Request &req, IConfig *configFile, Client *client, fd_set *master_read_set, int &max_fd);
		bool			handleDeleteRequest(Request &req, IConfig *configFile, Client *client, fd_set *master_read_set, int &max_fd);

		/* CGI.cpp */
		bool			isCgiFile(std::string &path, IConfig *configFile);
		bool 			handleCgiRequest(Request &req, std::string &path, pid_t &pid, int &fd, IConfig *configFile);
		
		void			setBody(const std::string &content) {body = content;}
		
		ServerConfig	*getDefaultConfig() { return _defaultConfig; }
		std::string		&getConnection() { return connection; }

};

#endif