/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IConfig.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:09:28 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/12 15:44:45 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACONFIG_HPP
#define ACONFIG_HPP

#include "Common.hpp"

class IConfig {
	public:
		IConfig() : _error_pages() {};
		virtual ~IConfig() { _error_pages.clear(); }
	
		std::map<int, std::string>			_error_pages;
		
		virtual	std::string					&getPath() = 0;
		virtual std::string 				&getRoot() = 0;
		virtual std::string 				&getAlias() = 0;
		virtual std::vector<std::string>	&getAllowedMethods() = 0;
		virtual std::string 				&getDefaultServerRoot() = 0;
		virtual std::string 				&getDefaultFile() = 0;
		virtual bool						&getDirectoryListing() = 0;
		virtual std::string 				&getUploadPath() = 0;
		virtual redirect 					&getRedirect() = 0;
		virtual std::vector<std::string> 	&getCgiExtensions() = 0;
		virtual const std::string			&getSingleCgiExtension(std::string &extension) = 0;
		virtual std::string 				&getCgiPath() = 0;
};

#endif
