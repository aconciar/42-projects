/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:25:18 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/12 15:43:35 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Common.hpp"
#include "Request.hpp"

class Client {

	private:
		int 		_client_fd;
		std::string _input_buffer;
		std::string _output_buffer;
		Request 	_current_request;

		bool		isCgi;
		int 		cgiFd;
		pid_t		cgiPid;
		std::string cgiBuffer;
		time_t		cgiStart;
	
	public:
		Client() :
			_client_fd(0),
			_input_buffer(""),
			_output_buffer(""),
			isCgi(false),
			cgiFd(-1),
			cgiPid(-1),
			cgiStart(0) {}
		Client(int client_fd) :
			_input_buffer(""),
			_output_buffer(""),
			isCgi(false),
			cgiFd(-1),
			cgiPid(-1),
			cgiStart(0) {
			_client_fd = client_fd;
		}
		~Client() {}

		void	clearCgiBuffer() { cgiBuffer.clear(); }

		void	setCgi(bool value) { isCgi = value; }
		void	setCgiBuffer(std::string buffer) { cgiBuffer = buffer; }
		void	setCgiFd(int fd) { cgiFd = fd; }
		void	setCgiPid(pid_t pid) { cgiPid = pid; }
		void	setCgiStart(time_t start) { cgiStart = start; }
		void	setRequest(Request req) { _current_request = req; }

		bool		getCgi() { return isCgi; }
		std::string &getCgiBuffer() { return cgiBuffer; }
		int			getCgiFd() { return cgiFd; }
		pid_t		getCgiPid() { return cgiPid; }
		time_t		getCgiStart() { return cgiStart; }
		Request 	&getRequest() { return _current_request; }
		
};

#endif