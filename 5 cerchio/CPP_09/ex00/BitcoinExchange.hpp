/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:54:51 by andrea            #+#    #+#             */
/*   Updated: 2024/10/19 00:41:03 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <exception>


class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void    printMap() const;
		bool    isValidInput(std::string date, double value) const;
		double  getExchangedRate(std::string date, double value) const;
		void    printExchangedRate(std::string date, double value, double exchangedRate) const;
		void    btcExchange(std::string filename);

	private:
		std::map<std::string, double> data;
};

#endif