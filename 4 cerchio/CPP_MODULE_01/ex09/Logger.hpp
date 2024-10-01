/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:25:53 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 14:32:38 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger
{
    public :
        Logger(std::string const &filename);
        ~Logger();
        void log(std::string const &dest, std::string const &message);

    private :
        std::string _filename;
        void logToConsole(std::string const &message);
        void logToFile(std::string const &message);
        std::string makeLogEntry(std::string const &message);
};

#endif