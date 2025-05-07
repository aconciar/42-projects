/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerManager.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:19:37 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/17 16:39:18 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerManager.hpp"
#include "SignalHandler.hpp"

void ServerManager::addServer(Server* server)
{
	servers.push_back(server);
	FD_SET(server->getServerFd(), &master_read_set);
	max_fd = std::max(max_fd, server->getServerFd());
}

void	ServerManager::shutdownServers()
{
    std::cout << PURPLE << "\n[Webserv] Cleaning up before shutdown..." << RESET << std::endl;

	for (std::vector<Server*>::iterator it = servers.begin(); it != servers.end(); it++)
	{
		int sockfd = (*it)->getServerFd();
		if (sockfd != -1)
		{
			close(sockfd);
			FD_CLR(sockfd, &master_read_set);
		}
	}
	std::cout << YELLOW << "[Webserv] Cleanup completed. Exiting now." << RESET << std::endl;
}

void ServerManager::run()
{
	while (!g_terminate)
	{
		fd_set read_set = master_read_set;
		fd_set write_set = master_write_set;

		struct timeval	timeout;
		timeout.tv_sec = TIMEOUT;
		timeout.tv_usec = 0;

		int activity = select(max_fd + 1, &read_set, &write_set, NULL, &timeout);
		if (!g_paused && activity == 0)
			std::cout << "Listening..." << std::endl;
		else if (activity < 0)
		{
			if (errno == EINTR)
				continue;
			perror("select");
			break;
		}
		for (std::vector<Server*>::iterator it = servers.begin(); it != servers.end(); it++)
		{
			if (!g_paused && FD_ISSET((*it)->getServerFd(), &read_set))
			{
				int new_fd = (*it)->handleNewConnection(&master_read_set);
				if (new_fd != -1)
					max_fd = std::max(max_fd, new_fd);
			}
			std::map<int, Client>::iterator it_clients = (*it)->getClients().begin();
			while (it_clients != (*it)->getClients().end())
			{
				int fd = it_clients->first;
				int cgiFd = it_clients->second.getCgiFd();
				++it_clients;
			
				if  (FD_ISSET(cgiFd, &read_set))
					(*it)->handleClientRead(cgiFd, &master_read_set, &master_write_set);
				if (FD_ISSET(fd, &read_set))
					(*it)->handleClientRead(fd, &master_read_set, &master_write_set);
				if (FD_ISSET(fd, &write_set) && (*it)->getBuffers().find(fd) != (*it)->getBuffers().end())
					(*it)->handleClientWrite(fd, &master_read_set, &master_write_set, max_fd);
			}
		}
		for (std::vector<Server *>::iterator it = servers.begin(); it != servers.end(); it++)
			(*it)->checkCgiTimeout(&master_read_set, &master_write_set);
	}
}
