/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:51:48 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/13 15:17:24 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"
#include "Request.hpp"

bool Request::isValid(Response &res)
{
	std::istringstream stream(_line);
	std::string first_line;

	getline(stream, first_line);
	std::istringstream fl_stream(first_line);
	if (!(fl_stream >> _method >> _path >> _version))
	{
		res.sendErrorResponse(400, "Bad request - stream", _defaultConfig);
		return (false);
	}
	if (_method != "GET" && _method != "POST" && _method != "DELETE")
	{
		res.sendErrorResponse(400, "Bad request - method", _defaultConfig);
		return (false);
	}
	if (_version != "HTTP/1.1")
	{
		res.sendErrorResponse(400, "Bad request - HTTP", _defaultConfig);
		return (false);
	}

	std::cout << GREEN << "Header is " << first_line << RESET << std::endl;
	
	std::string line;
	while (std::getline(stream, line)) {
		if (line.length() > 0 && line[line.length()-1] == '\r')
			line = line.substr(0, line.length()-1);
		if (line.empty())
			break;
		if (line.find(':') == std::string::npos)
			return (false);
		if (VERBOSE_MODE == 1)
			std::cout << GREEN << line << RESET << std::endl;
		setHeaders(line);
	}

	std::string content_length_str = getHeader("Content-Length");
    if (!content_length_str.empty())
    {
        int content_length = atoi(content_length_str.c_str());
        if (content_length > 0)
        {
            std::stringstream body_stream;
            body_stream << stream.rdbuf();

            _body = body_stream.str();
            if (_body.size() != static_cast<size_t>(content_length))
            {
                std::cout << "Error: Content-Length mismatch, received " << _body.size() << " bytes instead of " << content_length << std::endl;
                return false;
            }
        }
    }
	return (true);
}

void	Request::setHeaders(const std::string &line)
{
	size_t	pos = line.find(":");

	std::string key = line.substr(0, pos);
	std::string value = line.substr(pos + 2, line.length() - 1);

	std::pair<std::map<std::string, std::string>::iterator, bool> result;
	result = _headers.insert(std::make_pair(key, value));

	key.erase(0, key.find_first_not_of(" \t"));
	key.erase(key.find_last_not_of(" \t") + 1);
	value.erase(0, value.find_first_not_of(" \t"));
	value.erase(value.find_last_not_of(" \t") + 1);

	if (result.second == false)
		std::cout << "WARNING -- Header already exists" << std::endl;
}

std::string	&Request::getHeader(const std::string &key)
{
	std::map<std::string, std::string>::iterator it = _headers.find(key);
	if (it == _headers.end())
		return (_headers[""]);
	return (it->second);
}
