/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:25:24 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 14:54:15 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string const &filename) : _filename(filename)
{
}

Logger::~Logger() {}

void Logger::logToConsole(std::string const &message)
{
    std::cout << message << std::endl;
}

void Logger::logToFile(std::string const &message)
{
    std::ofstream file(_filename, std::ios::app);
    if (file.is_open())
    {
        file << message << std::endl;
        file.close();
    }
    else
    {
        std::cout << "Error: could not open file" << std::endl;
    }
}

std::string Logger::makeLogEntry(std::string const &message)
{
    std::string logEntry;
    std::time_t now = time(0);
    std::tm *timeinfo = localtime(&now);
    char buffer[80];

    strftime(buffer, 80, "[%Y-%m-%d %H:%M:%S] ", timeinfo);
    logEntry = buffer;
    logEntry += message;
    return (logEntry);
}

void Logger::log(std::string const &dest, std::string const &message)
{
    void (Logger::*logFuncs[])(std::string const &message) =
        {
            &Logger::logToConsole,
            &Logger::logToFile
        };

    std::string dests[] = {"console", "file"};
    std::string logEntry = makeLogEntry(message);
    int i = 0;

    while (i < 2)
    {
        if (dest == dests[i])
        {
            (this->*logFuncs[i])(logEntry);
            return;
        }
        i++;
    }
    std::cout << "Error : Invalid log destination'" << dest << "'" << std::endl;
}