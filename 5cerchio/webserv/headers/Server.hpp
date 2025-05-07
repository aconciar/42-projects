/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:30:55 by andrea            #+#    #+#             */
/*   Updated: 2025/03/12 17:05:56 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "Common.hpp"
#include "ServerConfig.hpp"
#include "Client.hpp"
#include "Response.hpp"
#include "SignalHandler.hpp"

class Server
{
	private:
		std::map<std::string, ServerConfig> _virtualHosts;
		ServerConfig 						*_defaultConfig;

		int							server_fd;
		int							max_fd;
		std::map<int, std::string>	buffers;
		std::map<int, Client>		clients;

	public:
		Server(ServerConfig &config) : 
			_virtualHosts(),
			_defaultConfig(new ServerConfig(config)),
			buffers(),
			clients() {
			server_fd = createServerSocket();
			if (server_fd == -1)
			{
				std::cerr << RED << "[Error] Failed to create the socket ... Shutdown triggered" << RESET << std::endl;			
				g_terminate = true;
			}
			max_fd = server_fd;
		}
		~Server() {
			close(server_fd);
			_virtualHosts.clear();
			clients.clear();
			buffers.clear();
			delete(_defaultConfig);
		}

		void 			addServerConfig(ServerConfig& config, std::string server_name) { _virtualHosts[server_name] = config; }
		int							getServerFd() { return server_fd; }
		std::map<int, Client>		&getClients() { return clients; }
		std::map<int, std::string>	&getBuffers() { return buffers; }
		ServerConfig				*getServerDefaultConfig() { return _defaultConfig; }
		
		/* ServerUtils.cpp */
		void			setNonBlocking(int fd);
		bool			isValidHttpReq(const std::string &buffer_read, int fd, Response &res);
		IConfig			*findServingPath(Request &req, ServerConfig *configFile);
		int				findClientByCgiFd(int cgiFd);
		void			checkCgiTimeout(fd_set *master_read_set, fd_set *master_write_set);
		int				createServerSocket();
		void			closeClientConnection(int fd, fd_set *master_read_set, fd_set *master_write_set);
		
		/* Server.cpp */
		void			handleCgiRead(int clientFd, int cgiFd, fd_set *master_read_set, fd_set *master_write_set);
		int				handleNewConnection(fd_set *master_read_set);
		void			handleClientRead(int fd, fd_set *master_read_set, fd_set *master_write_set);	
		void			handleClientWrite(int fd, fd_set *master_read_set, fd_set *master_write_set, int &rmax_fd);		
		ServerConfig	*getSpecificServerConfig(std::string &server_name);
		
		/* void			writeOnFile(const std::string &buffer, int fd); */
};

#endif