/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:55:29 by andrea            #+#    #+#             */
/*   Updated: 2024/08/27 19:46:50 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"
#include <iomanip>

#define color "\001\033[1;35m\002"
#define rst "\001\033[0;0m\002"

void	print_name(std::string str)
{
	unsigned int i;

	i = 0;
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9);
		std::cout << ".";
	}
	else
	{
		i = 0;
		while (i++ < 10 - str.length())
			std::cout << " ";
		std::cout << str;
	}
}


phonebook::phonebook()
{
	this->index = 0;
	this->contact_count = 0;
}

phonebook::~phonebook() {}

void phonebook::add_contact()
{
		contact new_contact;
		std::string input;

		std::cout << "Enter first name: ";
		std::cin >> input;
		new_contact.set_first_name(input);
		
		std::cout << "Enter last name: ";
		std::cin >> input;
		new_contact.set_last_name(input);

		std::cout << "Enter nickname: ";
		std::cin >> input;
		new_contact.set_nickname(input);

		std::cout << "Enter phone number: ";
		std::cin >> input;
		new_contact.set_number(input);

		std::cout << "Enter darkest secret: ";
		std::cin >> input;
		new_contact.set_secret(input);

		this->contacts[this->index] = new_contact;
		if (this->index == 7)
			this->index = 0;
		else
			this->index++;
		if (this->contact_count < 8)
			this->contact_count++;
}

void    phonebook::search_contact()
{
	int         i = 0;
	std::string input;

	if (this->contact_count == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}

	std::cout << color << "+----------+----------+----------+----------+" << rst << std::endl;
	std::cout << color << "|     index|first name| last name|  nickname|" << rst << std::endl;
	std::cout << color << "+----------+----------+----------+----------+" << rst << std::endl;

	while (i < this->contact_count)
	{
		std::cout << color << "|         " << rst;
		std::cout << i;
		std::cout << color << "|" << rst;
		print_name(this->contacts[i].get_first_name());
		std::cout << color << "|" << rst;
		print_name(this->contacts[i].get_last_name());
		std::cout << color << "|" << rst;
		print_name(this->contacts[i].get_nickname());
		std::cout << color << "|" << color << std::endl;
		i++;
	}
	std::cout << color << "+----------+----------+----------+----------+" << rst << std::endl;

	std::cout << "Enter index: ";
	std::cin >> input;
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		this->print_contact(input[0] - '0');
	else
		std::cout << "Invalid index" << std::endl;
}

void    phonebook::print_contact(int index)
{

	std::cout << color << "+----------+----------+----------+----------+" << rst << std::endl;
	std::cout << color << "|  Contact information for specified index  |" << rst << std::endl;
	std::cout << color << "+----------+----------+----------+----------+" << rst << std::endl;

	std::cout << "First name: " << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index].get_number() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index].get_secret() << std::endl;
}
