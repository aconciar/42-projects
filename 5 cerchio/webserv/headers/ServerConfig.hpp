/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:39:28 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/12 15:56:37 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERCONFIG_HPP
#define SERVERCONFIG_HPP

#include "Common.hpp"
#include "Router.hpp"

class Router;

class ServerConfig : public IConfig {
	
	private:
		std::vector<std::string>		_allowed_methods_server;
		std::vector<std::string>		_cgi_extensions;
		long long						_client_max_body_size;
		std::string						_default_file_server;
		bool							_directory_listing_server;
		std::string 					_host;
		std::vector<Router>				_locations;
		int								_port;
		std::string 					_root;
		std::vector<std::string> 		_server_names;
		std::string						_upload_path;

	public:
		ServerConfig() : 
			IConfig(),
			_allowed_methods_server(),
			_cgi_extensions(std::vector<std::string>()),
			_client_max_body_size(0),
			_directory_listing_server(false),
			_port(0) {
			_server_names = std::vector<std::string>();
			_locations = std::vector<Router>();
		}
		ServerConfig(int counter) :
			IConfig(),
			_allowed_methods_server(),
			_cgi_extensions(std::vector<std::string>()),
			_client_max_body_size(0),
			_directory_listing_server(false),
			_port(0),
			_counter(counter) {
			_server_names = std::vector<std::string>();
			_locations = std::vector<Router>();
		}
		~ServerConfig() {
			_allowed_methods_server.clear();
			_cgi_extensions.clear();
			_locations.clear();
			_server_names.clear();
		 }

		int		_counter;

		void	setAllowedMethods(std::vector<std::string> &methods) { _allowed_methods_server = methods; }
		void	setClientMaxBodySize(long long client_max_body_size) { _client_max_body_size = client_max_body_size; }
		void 	setDefaultFile(const std::string &default_file) { _default_file_server = default_file; }
		void	setDirectoryListing(bool directory_listing) { _directory_listing_server = directory_listing; }
		void	setErrorPage(int status_code, const std::string &path);
		void 	setHost(const std::string &host) { _host = host; }
		void 	setPort(int &port){ _port = port; }
		void 	setRoot(const std::string &root) { _root = root; }
		void 	setServerNames(std::vector<std::string> &server_names) { _server_names = server_names; }
		void 	setUploadPath(const std::string &path) { _upload_path = path; }

		std::string 				&getAlias() { static std::string ret = ""; return ret; }
		std::vector<std::string> 	&getAllowedMethods() { return _allowed_methods_server; }
		std::map<int, std::string>	&getAllErrorPages() { return _error_pages; }
		std::vector<Router>			&getAllLocations() { return _locations; }
		std::string 				&getCgiExtension() { static std::string ret = ""; return ret; }
		std::vector<std::string> 	&getCgiExtensions() { return _cgi_extensions; }
		std::string 				&getCgiPath() { static std::string ret = ""; return ret; }
		long long					&getClientMaxBodySize() { return _client_max_body_size; }
		std::string 				&getDefaultFile() { return _default_file_server; }
		std::string 				&getDefaultServerRoot() { return _root; }
		bool						&getDirectoryListing() { return _directory_listing_server; }
		std::string					&getErrorPage(int status_code);
		std::string 				&getHost() { return _host; }
		Router						*getLocation(std::string &location);
		std::string					&getPath() { static std::string ret = ""; return ret; }
		int							&getPort() { return _port; }
		redirect 					&getRedirect() { static redirect ret = { 0, ""}; return ret; }
		std::string 				&getRoot() { return _root; }
		std::vector<std::string> 	&getServerNames() { return _server_names; }
		const std::string			&getSingleCgiExtension(std::string &extension) { (void)extension; static const std::string ret; return ret; }
		std::string 				&getUploadPath() { return _upload_path; }
	
	
};

#endif