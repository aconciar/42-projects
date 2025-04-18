/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:01:34 by andrea            #+#    #+#             */
/*   Updated: 2024/10/10 19:10:43 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with this " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with his bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}