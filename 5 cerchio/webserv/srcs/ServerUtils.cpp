/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:58:26 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/17 16:55:26 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void    Server::setNonBlocking(int fd)
{
	int	flags;

	flags = fcntl(fd, F_GETFL, 0);
	if (flags == -1)
	{
		perror("fcntl get");
		exit(EXIT_FAILURE);
	}
	if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
	{
		perror("fcntl set");
		exit(EXIT_FAILURE);
	}
}

bool	Server::isValidHttpReq(const std::string &buffer_read, int fd, Response &res)
{
	Request	req(buffer_read, _defaultConfig);

	if (!req.isValid(res))
		return (false);
	clients[fd].setRequest(req);
	return (true);
}

int Server::findClientByCgiFd(int cgiFd)
{
    for (std::map<int, Client>::iterator it = clients.begin(); it != clients.end(); ++it)
	{
        if (it->second.getCgi() && it->second.getCgiFd() == cgiFd)
            return (it->first);
    }
    return (-1);
}

ServerConfig	*Server::getSpecificServerConfig(std::string &server_name) {
	std::map<std::string, ServerConfig>::iterator it = _virtualHosts.find(server_name);
	if (it == _virtualHosts.end())
		return _defaultConfig;
		
	return &(it->second);
}

IConfig		*Server::findServingPath(Request &req, ServerConfig *configFile) 
{
	std::string request_path = req.getPath();
	Router* best_match = NULL;
	size_t longest_match = 0;

	for (std::vector<Router>::iterator it = configFile->getAllLocations().begin();
		it != configFile->getAllLocations().end(); ++it) {
		std::string loc_path = it->getPath();
		
		if (VERBOSE_MODE == 1)
			std::cout << "Checking -" << loc_path << "- against -" << request_path << "-\n";
		if (request_path == loc_path) {
			if (loc_path.length() > longest_match) {
				longest_match = loc_path.length();
				best_match = &(*it);
			}
		}
		else if (request_path.find(loc_path) == 0) {
			if (loc_path == "/") {
				longest_match = loc_path.length();
				best_match = &(*it);
			}
			best_match = &(*it);
		}
	}

	if (VERBOSE_MODE == 1) {
		if (best_match)
			std::cout << "ConfigFile is: " << best_match->getPath() << std::endl;
		else
			std::cout << "ConfigFile is: default settings" << std::endl;	
	}

	return ((IConfig*)best_match ? (IConfig*)best_match : (IConfig*)configFile);
}

void	Server::checkCgiTimeout(fd_set *master_read_set, fd_set *master_write_set)
{
	time_t now = time(NULL);
	std::map<int, Client>::iterator it = clients.begin();
	while (it != clients.end())
	{
		std::map<int, Client>::iterator current = it++;
		Client &cli = current->second;

		if (cli.getCgi())
		{
			if (now - cli.getCgiStart() >= TIMEOUT_CGI)
			{
				kill(cli.getCgiPid(), SIGKILL);
				waitpid(cli.getCgiPid(), NULL, 0);
				FD_CLR(cli.getCgiFd(), master_read_set);
				close(cli.getCgiFd());

				Response r(current->first, _defaultConfig);
				r.sendErrorResponse(504, "CGI timeout", _defaultConfig);
				closeClientConnection(current->first, master_read_set, master_write_set);
			}
		}
	}
}

int Server::createServerSocket() {
    struct addrinfo hints;
    struct addrinfo *result;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    std::stringstream port_str;
    port_str << _defaultConfig->getPort();

    int status = getaddrinfo(_defaultConfig->getHost().c_str(), port_str.str().c_str(), &hints, &result);
    if (status != 0) {
		if (VERBOSE_MODE == 1)
       		std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
		return -1;
    }

    int server_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (server_fd == -1) {
        perror("socket");
        freeaddrinfo(result);
        return -1;
    }
    
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
    setNonBlocking(server_fd);

    if (bind(server_fd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("bind");
        close(server_fd);
        freeaddrinfo(result);
        return -1;
    }

    freeaddrinfo(result);
    if (listen(server_fd, BACKLOG) == -1) {
        perror("listen");
        close(server_fd);
        return -1;
    }
    
    return server_fd;
}

void    Server::closeClientConnection(int fd, fd_set *master_read_set, fd_set *master_write_set)
{
	FD_CLR(fd, master_read_set);
	FD_CLR(fd, master_write_set);

	buffers.erase(fd);
	clients.erase(fd);

	shutdown(fd, SHUT_RDWR);
	close(fd);
	
	if (fd == max_fd)
	{
        max_fd = server_fd;
        for (std::map<int, Client>::iterator it = clients.begin(); it != clients.end(); ++it)
            max_fd = std::max(max_fd, it->first);
    }
}

int Server::handleNewConnection(fd_set *master_read_set)
{
    struct sockaddr_in client_addr;
    socklen_t addr_size = sizeof(client_addr);
    
	if (VERBOSE_MODE == 1)
	{
		std::cout << "Accepting connection on port " << _defaultConfig->getPort() 
				<< " (server fd: " << server_fd << ")" << std::endl;	
	}
    
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
    
    if (client_fd == -1)
	{
        perror("accept error");
        return -1;
    }

    // Convert network byte order to host byte order for display
    // client_addr.sin_addr.s_addr is the IP in network byte order
    unsigned int client_ip = ntohl(client_addr.sin_addr.s_addr);
    unsigned short client_port = ntohs(client_addr.sin_port);
    
    // Break down the IP address into octets for display
    unsigned char ip_octets[4];
    ip_octets[0] = (client_ip >> 24) & 0xFF;  // First octet
    ip_octets[1] = (client_ip >> 16) & 0xFF;  // Second octet
    ip_octets[2] = (client_ip >> 8) & 0xFF;   // Third octet
    ip_octets[3] = client_ip & 0xFF;          // Fourth octet
    
	if (VERBOSE_MODE == 1)
	{
		std::cout << "New connection from "
				  << static_cast<int>(ip_octets[0]) << "."
				  << static_cast<int>(ip_octets[1]) << "."
				  << static_cast<int>(ip_octets[2]) << "."
				  << static_cast<int>(ip_octets[3])
				  << ":" << client_port
				  << " (client fd: " << client_fd << ")" << std::endl;
	}

    setNonBlocking(client_fd);
    FD_SET(client_fd, master_read_set);
    clients[client_fd] = Client(client_fd);
    return (client_fd);
}
