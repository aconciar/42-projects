/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:26:37 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/09 20:14:38 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <sstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <iomanip> 

class ScalarConverter
{
	public:
		static void    convert(std::string str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);

		static void    printChar(double value);
		static void    printInt(double value);
		static void    printFloat(double value);
		static void    printDouble(double value);
		static bool    isChar(const std::string &str);
		static bool    isInt(const std::string &str);
		static bool    isFloat(const std::string &str);
		static bool    isDouble(const std::string &str);
		static bool    isPseudoLiteral(const std::string &str);
};

#endif