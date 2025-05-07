/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:50:27 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/12 15:45:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "Common.hpp"
#include "ServerConfig.hpp"

class Response;

class Request {
	
	private:
		std::string							_line;
		std::string							_method;
		std::string							_path;
		std::string							_version;
		std::string							_body;
		std::map<std::string, std::string> 	_headers;
		ServerConfig						*_defaultConfig;

	public:
		Request() :
			_line(""),
			_method(""),
			_path(""),
			_version(""),
			_body(""),
			_headers(), 
			_defaultConfig(NULL) {}
		Request(const std::string &line, ServerConfig *defaultConfig) :
			_line(line),
			_method(""),
			_path(""),
			_version(""),
			_body(""),
			_headers(),
			_defaultConfig(defaultConfig) {}
		~Request() {}

		std::string							&getMethod() { return _method; }
		std::string							&getPath() { return _path; }
		std::string							&getVersion() { return _version; }
		std::string							&getBody() { return _body; }
		std::map<std::string, std::string>	&getHeaders() { return _headers; }
		std::string							&getHeader(const std::string &key);

		bool								isValid(Response &res);
		void								setMethod(const std::string &method) { _method = method; }
		void								setPath(const std::string &path) { _path = path; }
		void								setVersion(const std::string &version) { _version = version; }
		void								setBody(const std::string &body) { _body = body; }
		void								setHeaders(const std::string &line);
};

#endif