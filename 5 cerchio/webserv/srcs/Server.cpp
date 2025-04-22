/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:30:47 by andrea            #+#    #+#             */
/*   Updated: 2025/03/17 18:17:00 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Request.hpp"
#include "Response.hpp"

void	Server::handleCgiRead(int clientFd, int cgiFd, fd_set *master_read_set, fd_set *master_write_set)
{
	Client &cli = clients[clientFd];
	std::string 	host = cli.getRequest().getHeader("Host");
	ServerConfig	*config = getSpecificServerConfig(host);

	ssize_t n;
	char buffer[1024];
	while ((n = read(cgiFd, buffer, 1024)) > 0)
	{
		buffer[n] = '\0';
		cli.setCgiBuffer(cli.getCgiBuffer() + buffer);
		memset(buffer, 0, 1024);
	}
    if (!cli.getCgiBuffer().empty())
    {
        FD_CLR(cgiFd, master_read_set);
        close(cgiFd);
        waitpid(cli.getCgiPid(), NULL, 0);

		Response res(clientFd, config);
        res.setBody(cli.getCgiBuffer());
        res.setMimeType("text/html");
        bool keepAlive = res.sendResponse("OK");
        cli.setCgi(false);
		cli.setCgiFd(-1);
		cli.setCgiPid(-1);
		cli.clearCgiBuffer();

        if (!keepAlive)
            closeClientConnection(clientFd, master_read_set, master_write_set);
    }
    else
    {
        FD_CLR(cgiFd, master_read_set);
        close(cgiFd);
        kill(cli.getCgiPid(), SIGKILL);
        waitpid(cli.getCgiPid(), NULL, 0);
		Response res(clientFd, config);
        res.sendErrorResponse(500, "CGI read error", config);
        closeClientConnection(clientFd, master_read_set, master_write_set);
    }
}

void    Server::handleClientRead(int fd, fd_set *master_read_set, fd_set *master_write_set)
{
	char			temp[BUFFER_SIZE];
	ssize_t			bytes_read;
	std::string 	host = clients[fd].getRequest().getHeader("Host");
	ServerConfig	*config = getSpecificServerConfig(host);
	Response		res(fd, config);

	int clientFd = findClientByCgiFd(fd);
	if (clientFd != -1)
	{
		handleCgiRead(clientFd, fd, master_read_set, master_write_set);
		return ;
	}

	memset(temp, 0, BUFFER_SIZE);
    bytes_read = recv(fd, temp, BUFFER_SIZE, 0);
    
    // Check if connection is closed or error
    if (bytes_read <= 0)
    {
        if (bytes_read == 0)
        {
            // Client closed connection gracefully
            if (VERBOSE_MODE == 1)
                std::cerr << YELLOW << "Client " << fd << " closed connection" << RESET << std::endl;
        }
        else
        {
            // Error occurred
            if (VERBOSE_MODE == 1)
                std::cerr << RED << "Error reading from client " << fd << ": " << strerror(errno) << RESET << std::endl;
        }
        closeClientConnection(fd, master_read_set, master_write_set);
        return;
    }
    
    // If we got here, we have valid data
    buffers[fd] += std::string(temp, bytes_read);

	while (true)
	{
		memset(temp, 0, BUFFER_SIZE);
		bytes_read = recv(fd, temp, BUFFER_SIZE, 0);
		if (bytes_read <= 0)
			break ;
		buffers[fd] += std::string(temp, bytes_read);
	}
	memset(temp, 0, BUFFER_SIZE);
	if (buffers[fd].find("\r\n\r\n") != std::string::npos)
	{
		size_t contentLength = 0;
		size_t contentStart = buffers[fd].find("\r\n\r\n") + 4;
		std::string headers = buffers[fd].substr(0, contentStart);
		size_t pos = headers.find("Content-Length: ");
		if (pos != std::string::npos)
		{
			size_t end = headers.find("\r\n", pos);
			contentLength = std::atoi(headers.substr(pos + 15, end - (pos + 15)).c_str());
		}
		if (buffers[fd].size() >= contentStart + contentLength)
		{
			if ((long long)contentLength > config->getClientMaxBodySize() && config->getClientMaxBodySize() != 0)
			{
				res.sendErrorResponse(413, "Request Entity Too Large", config);
				return ;
			}
			if (isValidHttpReq(buffers[fd], fd, res))
				FD_SET(fd, master_write_set);
			else
				buffers.erase(fd);
		}
	}
	else
	{
		if (VERBOSE_MODE == 1)
			std::cerr << RED << "Request header not complete from client " << fd << RESET << std::endl;
		res.sendErrorResponse(400, "Bad request - Server", config);
		return ;
	}
}

void	Server::handleClientWrite(int fd, fd_set *master_read_set, fd_set *master_write_set, int &rmax_fd)
{
	std::string 	host = clients[fd].getRequest().getHeader("Host");
	Response		res(fd, getSpecificServerConfig(host));
	ServerConfig 	*configFile;

	host.empty()? configFile = _defaultConfig : configFile = getSpecificServerConfig(host);
	
	IConfig *configuration = findServingPath(clients[fd].getRequest(), configFile);
	
	if (clients[fd].getRequest().getMethod() == "GET")
		res.handleGetRequest(clients[fd].getRequest(), configuration, &clients[fd], master_read_set, rmax_fd);
	else if (clients[fd].getRequest().getMethod() == "POST")
		res.handlePostRequest(clients[fd].getRequest(), configuration, &clients[fd], master_read_set, rmax_fd);
	else if (clients[fd].getRequest().getMethod() == "DELETE")
		res.handleDeleteRequest(clients[fd].getRequest(), configuration, &clients[fd], master_read_set, rmax_fd);

	buffers[fd].clear();
	FD_CLR(fd, master_write_set);

	if (res.getConnection() == "close")
	{
		std::cout << RED << "Closing connection\n" << RESET;
		closeClientConnection(fd, master_read_set, master_write_set);
	}

	if (fd == max_fd)
	{
		while (FD_ISSET(max_fd, master_write_set) == 0)
			return ;
	}
}
