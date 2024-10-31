/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:01:25 by andrea            #+#    #+#             */
/*   Updated: 2024/10/10 19:10:36 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : _name(name), _weapon(Weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << _name << " attacks with this " << _weapon.getType() << std::endl;
}
