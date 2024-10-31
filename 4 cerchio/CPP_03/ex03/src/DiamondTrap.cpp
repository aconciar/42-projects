/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:30:30 by andrea            #+#    #+#             */
/*   Updated: 2024/10/15 18:38:59 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	_name = "Default";
	hitpoints = FragTrap::hitpoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Default has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	hitpoints = FragTrap::hitpoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << _name << " is been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other._name + "_clap_name"), ScavTrap(other._name), FragTrap(other._name)
{
	_name = other._name;
	hitpoints = FragTrap::hitpoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << _name << " is been created!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		hitpoints = FragTrap::hitpoints;
		energyPoints = ScavTrap::energyPoints;
		attackDamage = FragTrap::attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is been destroyed!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}