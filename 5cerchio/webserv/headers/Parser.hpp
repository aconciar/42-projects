/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                  		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:54:38 by ucolla            #+#    #+#             */
/*   Updated: 2025/02/02 15:57:38 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Common.hpp"
#include "IConfig.hpp"
#include "ServerConfig.hpp"
#include "Server.hpp"
#include "ServerManager.hpp"
#include "Router.hpp"

class Parser {
	
	private:
		std::vector<ServerConfig> 	_serverConfigs;
		std::ifstream 				_file;

	public:
		int				parsingCounter;
		
		Parser() :
			_serverConfigs(),
			_file(),
			parsingCounter(1) {}
		~Parser() {
			if (_file.is_open())
				_file.close();
			_serverConfigs.clear();
			// std::vector<ServerConfig>().swap(_serverConfigs);
		}
	
		/* ParserUtils.cpp */
		void			checkServerLine(std::string line);
		void			checkEmptyFile(std::ifstream &file);
		bool			hasAlpha(const std::string& str);
		bool			checkClosingBracket(std::string &line);
		void 			checkAfterBracket(std::string line, char c);
		void			invalidKeyword(std::istringstream &stream);
		void			aliasWarning(Router &location, int parsingCounter);
		std::string		trimLine(const std::string &line);
		void			parseClientMaxBodySize(std::string &client_max_body_size, ServerConfig &server);
		void			isEmpty(std::string &print, std::string &key, std::string param);
		std::vector<ServerConfig> &getServerConfigs() { return _serverConfigs; }
		
		/* Parser.cpp */
		void 			parseRouteLine(const std::string& line, Router &location);
		void 			parseServerLine(const std::string& line, ServerConfig& server);
		void 			routeParser(Router &location);
		bool 			parseConfigFile(const std::string &configFile);
		ServerConfig 	parseServerBlock(int counter);
		void			populateServerConfigs(ServerManager &manager);
		
		
};

#endif