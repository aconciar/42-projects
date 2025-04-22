/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerManager.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:33:55 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/12 15:56:48 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERMANAGER_HPP
#define SERVERMANAGER_HPP

#include "Server.hpp"

class ServerManager {
	
	private:
		std::vector<Server*> 	servers;
		fd_set 					master_read_set;
		fd_set 					master_write_set;
		int 					max_fd;
		
	public:
		ServerManager() : servers()
		{
			FD_ZERO(&master_read_set);
			FD_ZERO(&master_write_set);
			max_fd = 0;
		}
		~ServerManager()
		{
			for (std::vector<Server*>::iterator it = servers.begin(); it != servers.end(); it++) {
				delete(*it);
			}
			servers.clear();
		}
		
		void 					addServer(Server* server);
		void 					run();

		void					shutdownServers();
		std::vector<Server*>	&getServers() { return servers; }
	
};

#endif