/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:04:15 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/17 18:04:33 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"

bool	Response::isCgiFile(std::string &path, IConfig *configFile)
{
	size_t dotPos = path.find_last_of('.');
	std::string extension;
	if (dotPos == std::string::npos)
		extension = path.substr(0);
	else
		extension = path.substr(dotPos);
	std::string cgiExtension = configFile->getSingleCgiExtension(extension);

	if (VERBOSE_MODE == 1)
		std::cout << "Checking if " << extension << " is a CGI file\n";

	if (extension == cgiExtension)
	{
		cgi_extension = extension;		
		return (true);
	}
	return (false);
}

bool	Response::handleCgiRequest(Request &req, std::string &path, pid_t &cgiPid, int &cgiFd, IConfig *configFile)
{
	int pipeOut[2];

	if (pipe(pipeOut) == -1)
		return (sendErrorResponse(500, "Cannot create pipe", _defaultConfig));

	bool hasBody = false;
	if ((req.getMethod() == "POST" || req.getMethod() == "DELETE") && !req.getBody().empty())
		hasBody = true;

	int pipeIn[2];
	bool usePipeIn = false;
	if (hasBody)
	{
		if (pipe(pipeIn) == -1)
			return (sendErrorResponse(500, "Cannot create pipe", _defaultConfig));
		usePipeIn = true;
	}
	pid_t pid = fork();
	if (pid < 0)
		return (sendErrorResponse(500, "Fork failed", _defaultConfig));
	if (pid == 0)
	{
		close (pipeOut[0]);
		if (dup2(pipeOut[1], STDOUT_FILENO) == -1)
			_exit(1);
		close(pipeOut[1]);

		if (usePipeIn)
		{
			close(pipeIn[1]);
			if (dup2(pipeIn[0], STDIN_FILENO) == -1)
				_exit(1);
			close(pipeIn[0]);
		}
		else
		{
			int nullFd = open("/dev/null", O_RDONLY);
			if (nullFd >= 0)
			{
				dup2(nullFd, STDIN_FILENO);
				close(nullFd);
			}
		}
		std::vector<std::string> argv_vec;
		
		if (cgi_extension == ".sh")
			argv_vec.push_back("/usr/bin/bash");
		else
			argv_vec.push_back("/usr/bin/python3");
		argv_vec.push_back(path);
		argv_vec.push_back(std::string());

		std::vector<std::string> env_vec;
		env_vec.push_back("REQUEST_METHOD=" + req.getMethod());
		env_vec.push_back("SCRIPT_FILENAME=" + path);
		env_vec.push_back("SCRIPT_NAME=" + req.getPath());
		env_vec.push_back("SERVER_PROTOCOL=HTTP/1.1");
		env_vec.push_back("SERVER_SOFTWARE=webserv/1.0");
		std::string cl = req.getHeader("Content-Length");
		if (cl.empty())
			cl = "0";
		env_vec.push_back("CONTENT_LENGTH=" + cl);
		env_vec.push_back("CONTENT_TYPE=" + req.getHeader("Content-Type"));
		env_vec.push_back("SERVER_NAME=localhost");
		env_vec.push_back("SERVER_PORT=8080");
		if (!configFile->getUploadPath().empty())
			env_vec.push_back("UPLOAD_PATH=" + configFile->getUploadPath());	
		std::vector<char*> envp;
		for (size_t i = 0; i < env_vec.size(); i++)
			envp.push_back(const_cast<char*>(env_vec[i].c_str()));
		envp.push_back(NULL);

		std::vector<char*> argv_c;
		for (size_t i = 0; i < argv_vec.size(); i++)
			argv_c.push_back(const_cast<char*>(argv_vec[i].c_str()));
		argv_c[argv_c.size() - 1] = NULL;
		if (execve(argv_c[0], &argv_c[0], &envp[0]) == -1)
		{
			perror("execve error");
			_exit(1);
		}
	}
	close(pipeOut[1]);
	fcntl(pipeOut[0], F_SETFL, O_NONBLOCK);
	cgiFd = pipeOut[0];
	cgiPid = pid;
	if (usePipeIn)
	{
		close(pipeIn[0]);
		const std::string &body = req.getBody();
		if (!body.empty())
		{
			if (write(pipeIn[1], body.c_str(), body.size()) == -1)
				return (sendErrorResponse(500, "Cannot write to pipe", _defaultConfig));
		}
		close(pipeIn[1]);
	}
	return (true);
}
