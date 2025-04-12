/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:47:41 by andrea            #+#    #+#             */
/*   Updated: 2024/12/28 18:53:32 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <iostream>
#include <cstdio>
#include <map>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 1024

void set_non_blocking(int fd)
{
	int flags;

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

int create_server_socket(struct sockaddr_in *address)
{
	int server_fd;

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

void handle_new_connection(int server_fd, struct pollfd *fds, int &nfds, std::map<int, std::string> &buffers)
{
	struct sockaddr_in	address;
	socklen_t			addrlen;
	int					client_fd;

	addrlen = sizeof(address);
	client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen);
	if (client_fd == -1)
	{
		perror("accept");
		return;
	}
	set_non_blocking(client_fd);
	fds[nfds].fd = client_fd;
	fds[nfds].events = POLLIN;
	buffers[client_fd] = "";
	nfds++;
	std::cout << "Nuovo client connesso: " << client_fd << std::endl;
}

void handle_client_read(int fd, std::map<int, std::string> &buffers, struct pollfd *fds, int i)
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
			fds[i].events = POLLOUT;
		}
	}
}

void handle_client_write(int fd, std::map<int, std::string> &buffers, struct pollfd *fds, int i)
{
	std::string	response;
	ssize_t		bytes_sent;

	response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!\r\n";
	bytes_sent = send(fd, response.c_str(), response.size(), 0);
	if (bytes_sent == -1)
	{
		perror("send");
		close(fd);
		buffers.erase(fd);
	}
	else
	{
		std::cout << "Risposta inviata al client " << fd << std::endl;
		buffers[fd].clear();
		fds[i].events = POLLIN;
	}
}

void server_loop(int server_fd)
{
	struct pollfd fds[MAX_CLIENTS];
	std::map<int, std::string> buffers;
	int nfds = 1;

	fds[0].fd = server_fd;
	fds[0].events = POLLIN;
	while (true)
	{
		int poll_count = poll(fds, nfds, -1);
		if (poll_count == -1)
		{
			perror("poll");
			break;
		}
		for (int i = 0; i < nfds; i++)
		{
			if (fds[i].revents & POLLIN)
			{
				if (fds[i].fd == server_fd)
					handle_new_connection(server_fd, fds, nfds, buffers);
				else
					handle_client_read(fds[i].fd, buffers, fds, i);
			}
			else if (fds[i].revents & POLLOUT)
				handle_client_write(fds[i].fd, buffers, fds, i);
			else if (fds[i].revents & (POLLHUP | POLLERR))
			{
				std::cout << "Errore client: " << fds[i].fd << std::endl;
				close(fds[i].fd);
				buffers.erase(fds[i].fd);
				fds[i] = fds[nfds - 1];
				nfds--;
				i--;
			}
		}
	}
}

int main(void)
{
	int server_fd;
	struct sockaddr_in address;

	server_fd = create_server_socket(&address);
	server_loop(server_fd);
	close(server_fd);
	return (0);
}