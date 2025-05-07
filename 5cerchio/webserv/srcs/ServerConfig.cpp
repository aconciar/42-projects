/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:55:28 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/12 16:05:10 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerConfig.hpp"

/* SETTER */
void	ServerConfig::setErrorPage(int status_code, const std::string &path) {
	std::map<int, std::string>::iterator it = _error_pages.find(status_code);
	if (it == _error_pages.end())
		_error_pages[status_code] = path;
}

/* GETTER */
std::string	&ServerConfig::getErrorPage(int status_code) {
	std::map<int, std::string>::iterator it = _error_pages.find(status_code);
	if (_error_pages.size() > 0 && it != _error_pages.end())
	{
		return it->second;
	}
	static std::string ret = "";
	return ret;
}

Router	*ServerConfig::getLocation(std::string &location) {
	for (std::vector<Router>::iterator it = _locations.begin(); it != _locations.end(); it++) {
		if (it->getPath() == location)
			return &(*it);
	}
	return NULL;
}
