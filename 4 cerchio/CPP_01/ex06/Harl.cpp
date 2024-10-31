/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:35:57 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/01 15:58:20 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	std::cout << "\n[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "\n[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "\n[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "\n[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	int levelSwitch = -1;

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*complaints[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	while (i < 4)
	{
		if (levels[i] == level)
		{
			levelSwitch = i;
			break;
		}
		i++;
	}

	switch (levelSwitch)
	{
		case (0):
		{
			(this->*complaints[0])();
			levelSwitch++;
		}
		case (1):
		{
			(this->*complaints[1])();
			levelSwitch++;
		}
		case (2):
		{
			(this->*complaints[2])();
			levelSwitch++;
		}
		case (3):
		{
			(this->*complaints[3])();
			break;
		}
		case (-1):
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
