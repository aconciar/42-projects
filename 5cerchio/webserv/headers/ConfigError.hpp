/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigError.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:36:12 by ucolla            #+#    #+#             */
/*   Updated: 2025/02/20 12:29:08 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGERROR_HPP
#define CONFIGERROR_HPP

class ConfigError : public std::exception {
	
	protected:
		std::string _msg;
		int			_counter;
		
	public:
		ConfigError(const std::string& msg, const int counter) : _msg(msg), _counter(counter) {}
		virtual ~ConfigError() throw() {}
		virtual const char* what() const throw() { return _msg.c_str(); }
		int getCounter() const { return _counter; }
};

class PortError : public ConfigError {

	public:
		PortError(const std::string& msg, int counter) : ConfigError(msg, counter) {}
};

class MethodError : public ConfigError {

	public:
		MethodError(const std::string& msg, int counter) : ConfigError(msg, counter) {}
};

class ServerBlockError : public ConfigError {

	public:
		ServerBlockError(const std::string& msg, int counter) : ConfigError(msg, counter) {}
};

class LocationBlockError : public ConfigError {
	
	public:
		LocationBlockError(const std::string& msg, int counter) : ConfigError(msg, counter) {}
};

class InvalidKeywordError : public ConfigError {

	public:
		InvalidKeywordError(const std::string& msg, int counter) : ConfigError(msg, counter) {}
};

class EmptyFile : public ConfigError {

	public:
		EmptyFile(const std::string& msg, int counter) : ConfigError(msg, counter) {}
};

class ConfigFileError : public ConfigError {

	public:
		ConfigFileError(const std::string& msg, int counter) : ConfigError(msg, counter) {}
};

#endif
