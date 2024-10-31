/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:28:58 by andrea            #+#    #+#             */
/*   Updated: 2024/10/15 16:06:43 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitpoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Default has been created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitpoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name)
{
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		this->hitpoints = other.hitpoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->energyPoints > 0 && this->hitpoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " viciously attack " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (this->energyPoints == 0)
		std::cout << "ScavTrap " << this->name << " is out of energy!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is out of hitpoints" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode!" << std::endl;
}
