/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:54:26 by andrea            #+#    #+#             */
/*   Updated: 2024/10/19 00:41:16 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::string filename;

	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	BitcoinExchange exchange("data.csv");

	filename = argv[1];
	exchange.btcExchange(filename);
	return (0);
}