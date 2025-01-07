/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:21:03 by andrea            #+#    #+#             */
/*   Updated: 2025/01/04 14:11:01 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <sstream>

#define PORT 8080
#define BACKLOG 1
#define BUFFER_SIZE 1024

void	set_non_blocking(int fd)
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

int	create_server_socket(struct sockaddr_in *address)
{
	int	server_fd;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	set_non_blocking(server_fd);
	address->sin_family = AF_INET;
	address->sin_addr.s_addr = INADDR_ANY;
	address->sin_port = htons(PORT);
	if (bind(server_fd, (struct sockaddr *)address, sizeof(*address)) == -1)
	{
		perror("bind");
		close(server_fd);
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, BACKLOG) == -1)
	{
		perror("listen");
		close(server_fd);
		exit(EXIT_FAILURE);
	}
	return (server_fd);
}

void	handle_new_connection(int server_fd, fd_set *master_set, int *max_fd)
{
	int			client_fd;
	socklen_t	addrlen;
	struct sockaddr_in	address;

	addrlen = sizeof(address);
	client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen);
	if (client_fd == -1)
		perror("accept");
	else
	{
		set_non_blocking(client_fd);
		FD_SET(client_fd, master_set);
		if (client_fd > *max_fd)
			*max_fd = client_fd;
		std::cout << "Nuovo client connesso: " << client_fd << std::endl;
	}
}

void	handle_client_except(int fd, fd_set *master_set, fd_set *master_read_set, fd_set *master_write_set, std::map<int, std::string> &buffers)
{
	std::cout << "Errore client: " << fd << std::endl;
	close(fd);
	FD_CLR(fd, master_set);
	FD_CLR(fd, master_read_set);
	FD_CLR(fd, master_write_set);
	buffers.erase(fd);
}

void	handle_client_write(int fd, fd_set *master_write_set, std::map<int, std::string> &buffers)
{
	std::string	response;
	ssize_t		bytes_sent;

	response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!\r\n";
	bytes_sent = 0;
	while (bytes_sent < (ssize_t)response.size())
	{
		ssize_t res = send(fd, response.c_str() + bytes_sent, response.size() - bytes_sent, 0);
		if (res == -1)
		{
			perror("send");
			close(fd);
			buffers.erase(fd);
			FD_CLR(fd, master_write_set);
			return ;
		}
		bytes_sent += res;
	}	
	std::cout << "Risposta inviata al client " << fd << std::endl;
	buffers[fd].clear();
	FD_CLR(fd, master_write_set);
}

bool	is_valid_http_request(const std::string &request)
{
	std::istringstream	stream(request);
	std::string			method;
	std::string			path;
	std::string			version;

	if (!(stream >> method >> path >> version))
	{
		std::cout << "Request not valid" << std::endl;
		return (false);
	}
	if (method != "GET" && method != "POST" && method != "DELETE")
	{
		std::cout << "Request not valid: Method not supported (" << method << ")" << std::endl;
		return (false);
	}
	if (version != "HTTP/1.1" && version != "HTTP/1.0")
	{
		std::cout << "Request not valid: HTTP Version not supported (" << version << ")" << std::endl;
		return (false);
	}
	std::string line;
	while (std::getline(stream, line) && line != "\r")
	{
		if (line.find(':') == std::string::npos)
		{
			std::cout << "Request not valid: Invalid Header (" << line << ")" << std::endl;
			return (false);
		}
	}
	std::cout << "Request valid" << std::endl;
	return (true);
}


void	handle_client_read(int fd, fd_set *master_write_set, std::map<int, std::string> &buffers)
{
	char temp[BUFFER_SIZE];
	int bytes_read;

	memset(temp, 0, BUFFER_SIZE);
	bytes_read = recv(fd, temp, BUFFER_SIZE - 1, 0);
	if (bytes_read <= 0)
	{
		if (bytes_read == 0)
			std::cout << "Client disconnesso: " << fd << std::endl;
		else
			perror("recv");
		close(fd);
		buffers.erase(fd);
	}
	else
	{
		buffers[fd] += std::string(temp);
		if (buffers[fd].find("\r\n\r\n") != std::string::npos)
		{
			std::cout << "Ricevuto dal client " << fd << ": " << buffers[fd] << std::endl;
			if (is_valid_http_request(buffers[fd]))
				FD_SET(fd, master_write_set);
			else
				buffers.erase(fd);
		}
	}
}


void	server_loop(int server_fd)
{
	fd_set						master_read_set;
	fd_set						master_write_set;
	fd_set						master_except_set;
	fd_set						read_fds;
	fd_set						write_fds;
	fd_set						except_fds;
	std::map<int, std::string>	buffers;
	int							max_fd;

	FD_ZERO(&master_read_set);
	FD_ZERO(&master_write_set);
	FD_ZERO(&master_except_set);
	FD_SET(server_fd, &master_read_set);
	FD_SET(server_fd, &master_except_set);
	max_fd = server_fd;

	while (true)
	{
		std::cout << "\n\nSelect" << std::endl;
		read_fds = master_read_set;
		write_fds = master_write_set;
		except_fds = master_except_set;
		if (select(max_fd + 1, &read_fds, &write_fds, &except_fds, NULL) == -1)
		{
			perror("select");
			break;
		}
		for (int fd = 0; fd <= max_fd; ++fd)
		{
			std::cout << "\nfd: " << fd << std::endl;
			std::cout << "master_read_set: " << FD_ISSET(fd, &master_read_set) << std::endl;
			std::cout << "master_write_set: " << FD_ISSET(fd, &master_write_set) << std::endl;
			std::cout << "master_except_set: " << FD_ISSET(fd, &master_except_set) << std::endl;
			if (FD_ISSET(fd, &read_fds))
			{
				if (fd == server_fd)
					handle_new_connection(server_fd, &master_read_set, &max_fd);
				else
					handle_client_read(fd, &master_write_set, buffers);
			}
			if (FD_ISSET(fd, &write_fds))
			{
				std::cout << "entro in write" << std::endl;
				handle_client_write(fd, &master_write_set, buffers);
			}
			if (FD_ISSET(fd, &except_fds))
			{
				std::cout << "entro in except" << std::endl;
				handle_client_except(fd, &master_except_set, &master_read_set, &master_write_set, buffers);
			}
		}
	}
}

int	main(void)
{
	int			server_fd;
	struct sockaddr_in	address;

	server_fd = create_server_socket(&address);
	server_loop(server_fd);
	close(server_fd);
	return (0);
}
