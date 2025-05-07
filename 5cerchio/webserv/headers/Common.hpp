/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:35:09 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/17 16:55:38 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HPP	
#define COMMON_HPP

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <typeinfo>
#include <string.h> 
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <vector>

#include "ConfigError.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

#define PORT_ERROR "PortError"
#define METHOD_ERROR "MethodError"
#define SERVER_BLOCK_ERROR "ServerBlockError"
#define LOCATION_BLOCK_ERROR "LocationBlockError"
#define INVALID_KEYWORD_ERROR "InvalidKeywordError"
#define CONFIG_FILE_ERROR "ConfigFileError"
#define EMPTY_FILE_ERROR "EmptyFileError"
#define MISSING_LOCATION_ERROR "MissingLocationError"

#define DEFAULT_CONFIG_FILE "./utils/configs/default_config.conf"

#define TIMEOUT	10
#define TIMEOUT_CGI	5


#ifndef VERBOSE_MODE
#define VERBOSE_MODE 0
#endif

typedef struct redirect_s {
	int			status_code;
	std::string	path;
}	redirect;

#define BACKLOG 1
#define BUFFER_SIZE 1024

#endif
