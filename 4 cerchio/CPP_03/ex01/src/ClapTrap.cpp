/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:03 by andrea            #+#    #+#             */
/*   Updated: 2024/10/15 16:11:42 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
	std::cout << "ClapTrap Default is ready!" << std::endl;
	this->name = "Deafult";
	this->hitpoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) 
{
	std::cout << "ClapTrap " << name << " is ready!" << std::endl;
	this->name = name;
	this->hitpoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitpoints(other.hitpoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap " << this->name << " is ready!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->energyPoints > 0 && this->hitpoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (this->energyPoints == 0)
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is out of hitpoints" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitpoints <= 0)
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
	else
	{
		this->hitpoints -= amount;
		std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << this->name << " has " << this->hitpoints << " hitpoints left!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hitpoints += amount;
	if (this->energyPoints > 0 && this->hitpoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " has been repaired for " << amount << " hitpoints!" << std::endl;
		std::cout << "ClapTrap " << this->name << " has " << this->hitpoints << " hitpoints!" << std::endl;
		this->energyPoints--;
	}
	else if (this->energyPoints == 0)
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is out of hitpoints" << std::endl;
}