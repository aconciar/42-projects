/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:28:31 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/01 16:03:05 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " is destroyed." << std::endl;
}

void   Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout << _name << " : Braiiiiiiinnnssss..." << std::endl;
}