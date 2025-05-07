/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:29:49 by ucolla            #+#    #+#             */
/*   Updated: 2025/01/24 11:39:36 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Router.hpp"
#include "ServerConfig.hpp"

Router::Router(std::string& default_root, IConfig* defaultConfig) :
	IConfig(),
	_alias(""),
    _allowed_methods(),
    _cgi_extensions(),
    _cgi_path(""),
    _default_file(""),
    _default_server_root(default_root),
    _directory_listing(false),
    _path(""),
    _redirect_config(redirect()),
    _root(""),
    _upload_dir(""),
    _defaultConfig(defaultConfig) {}

Router::Router() :
	IConfig(),
	_alias(""),
    _allowed_methods(),
    _cgi_extensions(),
    _cgi_path(""),
    _default_file(""),
    _default_server_root(""),
    _directory_listing(false),
    _path(""),
    _redirect_config(),
    _root(""),
    _upload_dir(""),
    _defaultConfig(NULL) {}

Router::~Router() {
   _allowed_methods.clear();
}

Router::Router(const Router& other) :
	IConfig(),
	_default_server_root(other._default_server_root),
	_directory_listing(other._directory_listing),
	_redirect_config(other._redirect_config),
	_defaultConfig(other._defaultConfig) {
	_path = other._path;
	_root = other._root;
	_alias = other._alias;
	_default_file = other._default_file;
	_upload_dir = other._upload_dir;
	_cgi_extensions = other._cgi_extensions;
	_cgi_path = other._cgi_path;
	_allowed_methods = other._allowed_methods;
}

Router& Router::operator=(const Router& other) {
	if (this != &other) {
		_defaultConfig = other._defaultConfig;
		_default_server_root = other._default_server_root;
		_directory_listing = other._directory_listing;
		_redirect_config = other._redirect_config;
		_path = other._path;
		_root = other._root;
		_alias = other._alias;
		_default_file = other._default_file;
		_upload_dir = other._upload_dir;
		_cgi_extensions = other._cgi_extensions;
		_cgi_path = other._cgi_path;
		_allowed_methods = other._allowed_methods;
	}
	return *this;
}

const std::string	&Router::getSingleCgiExtension(std::string &extension) {
	
	for (std::vector<std::string>::iterator it = _cgi_extensions.begin(); it != _cgi_extensions.end(); it++)
	{
		if (*it == extension)
			return *it;
	}
	static const std::string empty_string;
	return empty_string;
}
