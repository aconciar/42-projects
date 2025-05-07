/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:18:17 by andrea            #+#    #+#             */
/*   Updated: 2024/10/19 21:24:08 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>
#include <sstream>

bool    parse(const std::string &str)
{
	std::istringstream iss(str);
	std::string token;
	int digits = 0;
	int operators = 0;

	while (std::getline(iss, token, ' '))
	{
		if (isdigit(token[0]) && token.size() == 1)
			digits++;
		else if ((token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') && token.size() == 1)
			operators++;
		else
			return (false);
	}
	if (digits - operators != 1)
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::string str = argv[1];
	if (!parse(str))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	RPN rpn(str);
	return (0);
}