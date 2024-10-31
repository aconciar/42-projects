/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:28:31 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/01 16:01:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie() : _name("default")
{
	std::cout << "Zombie " << _name << " created" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << _name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " is destroyed" << std::endl;
}

void    Zombie::announce()
{
    std::cout << _name << " : Braiiiiiiinnnssss..." << std::endl;
}