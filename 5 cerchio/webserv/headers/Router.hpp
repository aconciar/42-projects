/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:41:53 by ucolla            #+#    #+#             */
/*   Updated: 2025/02/04 16:58:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Common.hpp"
#include "IConfig.hpp"
#include "ServerConfig.hpp"

class Router : public IConfig {
	
	private:
		std::string					_alias;
		std::vector<std::string>	_allowed_methods;
		std::vector<std::string>	_cgi_extensions;
		std::string					_cgi_path;
		std::string					_default_file;
		std::string					_default_server_root;
		bool						_directory_listing;
		std::string					_path;
		redirect					_redirect_config;
		std::string					_root;
		std::string					_upload_dir;

		IConfig 					*_defaultConfig;
						
	public:
		Router(std::string &default_root, IConfig *defaultConfig);
		Router();
		~Router();
		Router(const Router& other);
		Router& operator=(const Router& other);

		void 	setAlias(std::string alias) { _alias = alias; }
		void 	setAllowedMethods(std::vector<std::string> allowed_methods) { _allowed_methods = allowed_methods; }
		void 	setCgiExtension(std::vector<std::string> cgi_extensions) { _cgi_extensions = cgi_extensions; }
		void 	setCgiPath(std::string cgi_path) { _cgi_path = cgi_path; }
		void 	setDefaultFile(std::string file) { _default_file = file; }
		void 	setDefaultServerRoot(std::string root) { _default_server_root = root; }
		void 	setDirectoryListing(bool directory_listing) { _directory_listing = directory_listing; }
		void 	setPath(std::string path) { _path = path; }
		void 	setRedirect(redirect redirect_config) { _redirect_config = redirect_config; }
		void 	setRoot(std::string root) { _root = root; }
		void 	setUploadDir(std::string upload_dir) { _upload_dir = upload_dir; }

		std::string 				&getAlias() { return _alias; }
		std::vector<std::string> 	&getAllowedMethods() { return _allowed_methods; }
		std::vector<std::string> 	&getCgiExtensions() { return _cgi_extensions; }
		std::string 				&getCgiPath() { return _cgi_path; }
		std::string 				&getDefaultFile() { return _default_file; }
		std::string 				&getDefaultServerRoot() { return _default_server_root; }
		bool 						&getDirectoryListing() { return _directory_listing; }
		std::string					&getPath() { return _path; }
		redirect 					&getRedirect() { return _redirect_config; }
		std::string 				&getRoot() { return _root; }
		const std::string			&getSingleCgiExtension(std::string &extension);
		std::string 				&getUploadPath() { return _upload_dir; }

};

#endif
