/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:18:19 by andrea            #+#    #+#             */
/*   Updated: 2024/10/15 16:01:13 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default has been created!" << std::endl;
	this->hitpoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " has been created!" << std::endl;
	this->hitpoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name)
{
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "FragTrap " << this->name << " has been created!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " high fives guys!" << std::endl;
}
