/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:54:36 by andrea            #+#    #+#             */
/*   Updated: 2024/10/21 15:13:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		throw (std::exception());
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string value;

		if (std::getline(ss, date, ',') && std::getline(ss, value, ','))
		{
			data[date] = std::atof(value.c_str());
		}
		else
		{
			std::cerr << "Error: could not parse line" << std::endl;
			throw (std::exception());
		}
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : data(other.data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		data = other.data;
	}
	return (*this);
}

bool BitcoinExchange::isValidInput(std::string date, double value) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: invalid date" << std::endl;
		return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Error: invalid date" << std::endl;
		return (false);
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		std::cerr << "Error: invalid date" << std::endl;
		return (false);
	}
	if (month == 2)
	{
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > 29 || (day > 28 && !leap))
		{
			std::cerr << "Error: invalid date" << std::endl;
			return (false);
		}
	}
	if (value < 0 || value > 1000)
	{
		if (value < 0)
			std::cerr << "Error: not a positive number" << std::endl;
		else
			std::cerr << "Error: too large number" << std::endl;
		return (false);
	}
	return (true);
}

double  BitcoinExchange::getExchangedRate(std::string date, double value) const
{
	std::map<std::string, double>::const_iterator it = data.lower_bound(date);
	if (it == data.end())
	{
		it--;
	}
	else if (it->first != date)
	{
		if (it == data.begin())
		{
			std::cerr << "Error: no data available for dates before " << date << std::endl;
			return (-1);
		}
		it--;
	}
	return (value * it->second);
}

void    BitcoinExchange::printExchangedRate(std::string date, double value, double exchangedRate) const
{
	if (exchangedRate == -1)
		return ;
	std::cout << date << " => " << value << " = " << exchangedRate << std::endl;
}

std::string ft_strtrim(std::string str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	if (start == std::string::npos || end == std::string::npos)
		return ("");
	return (str.substr(start, end - start + 1));
}

void BitcoinExchange::btcExchange(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		throw (std::exception());
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string str_value;

		if (line == "date | value")
			continue ;
		else if (std::getline(ss, date, '|') && std::getline(ss, str_value))
		{
			date = ft_strtrim(date);
			str_value = ft_strtrim(str_value);
			double value = std::atof(str_value.c_str());
			if (isValidInput(date, value))
			{
				double ExchangedRate = getExchangedRate(date, value);
				printExchangedRate(date, value, ExchangedRate);
			}
		}
		else
		{
			std::cerr << "Error: bad input =>" << line << std::endl;
		}
	}
	file.close();
}

void BitcoinExchange::printMap() const
{
	for (std::map<std::string, double>::const_iterator it = data.begin(); it != data.end(); ++it)
	{
		std::cout << "Data: " << it->first << ", Valore: " << it->second << std::endl;
	}
}
