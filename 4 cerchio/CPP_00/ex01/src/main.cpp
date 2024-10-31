/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:17:38 by andrea            #+#    #+#             */
/*   Updated: 2024/10/10 17:35:31 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

int main()
{
	phonebook   phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Error: '" << command << "' is not a valid command. Please use 'ADD', 'SEARCH', or 'EXIT'." << std::endl;
	}
	return (0);
}