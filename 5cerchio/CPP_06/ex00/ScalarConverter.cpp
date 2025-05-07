/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:27:01 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/10 15:46:00 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

bool	isNaN(double value)
{
	return (value != value);
}

bool	isInf(double value)
{
	return (value == std::numeric_limits<double>::infinity() ||
	value == -std::numeric_limits<double>::infinity());
}

int	stringToInt(const std::string &str)
{
	int value;
	std::stringstream ss(str);

	ss >> value;
	if (ss.fail())
		throw std::invalid_argument("Error: invalid argument");
	return (value);
}

float	stringToFloat(const std::string &str)
{
	float value;
	std::stringstream ss(str);

	ss >> value;
	if (ss.fail())
		throw std::invalid_argument("Error: invalid argument");
	return (value);
}

double	stringToDouble(const std::string &str)
{

	double value;
	std::stringstream ss(str);

	if (str == "nan")
        return (std::numeric_limits<double>::quiet_NaN());
    else if (str == "+inf" || str == "inf")
        return (std::numeric_limits<double>::infinity());
    else if (str == "-inf") {
        return (-std::numeric_limits<double>::infinity()); }

	ss >> value;
	if (ss.fail())
		throw std::invalid_argument("Error: invalid argument");
	return (value);
}

void    ScalarConverter::convert(std::string str)
{
	if (isPseudoLiteral(str))
	{
		double value = stringToDouble(str);
		printChar(std::numeric_limits<double>::quiet_NaN());
		printInt(std::numeric_limits<double>::quiet_NaN());
		printFloat(value);
		printDouble(value);
		return ;
	}
	try 
	{
		if (isChar(str))
		{
			char value = str[0];
			printChar(static_cast<double>(value));
			printInt(static_cast<double>(value));
			printFloat(static_cast<double>(value));
			printDouble(static_cast<double>(value));
		}
		else if (isInt(str))
		{
			int value = stringToInt(str);
			printChar(static_cast<double>(value));
			printInt(static_cast<double>(value));
			printFloat(static_cast<double>(value));
			printDouble(static_cast<double>(value));
		}
		else if (isFloat(str))
		{
			float value = stringToFloat(str);
			printChar(static_cast<double>(value));
			printInt(static_cast<double>(value));
			printFloat(static_cast<double>(value));
			printDouble(static_cast<double>(value));
		}
		else if (isDouble(str))
		{
			double value = stringToDouble(str);
			printChar(value);
			printInt(value);
			printFloat(value);
			printDouble(value);
		}
		else
			std::cout << "Error: invalid argument" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: Conversion failed" << std::endl;
	}
}	

bool    ScalarConverter::isChar(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string &str)
{
	if (str.empty())
		return (false);
	
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return (false);
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &str)
{
	if (str.empty() || str[str.length() - 1] != 'f')
		return (false);
	std::string strWithoutF = str.substr(0, str.length() - 1);
	return (isDouble(strWithoutF));
}

bool	ScalarConverter::isDouble(const std::string &str)
{
	size_t	i = 0;
	bool	point = false;

	if (str.empty())
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			if (point)
				return (false);
			point = true;
		}
		else if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	if (i > 0)
		return (true);
	return (false);
}

bool	ScalarConverter::isPseudoLiteral(const std::string &str)
{
	if (str == "+inf" || str == "-inf" || str == "nan")
		return (true);
	return (false);
}

void    ScalarConverter::printChar(double value)
{
	std::cout << "char: ";
	if (isNaN(value) || isInf(value) ||
		value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<int>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void    ScalarConverter::printInt(double value)
{
	std::cout << "int: ";
	if (isNaN(value) || isInf(value) ||
		value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void    ScalarConverter::printFloat(double value)
{
	std::cout << "float: " << std::setprecision(6) << static_cast<float>(value);
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void    ScalarConverter::printDouble(double value)
{
	std::cout << "double: " << std::setprecision(6) << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}