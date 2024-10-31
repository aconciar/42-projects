/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:27:02 by andrea            #+#    #+#             */
/*   Updated: 2024/10/10 14:52:22 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = (argv[i]);
			for (size_t j = 0; j < str.length(); j++)
				std::cout << (char)std::toupper(str[j]);
			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
