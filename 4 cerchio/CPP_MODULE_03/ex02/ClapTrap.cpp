/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:03 by andrea            #+#    #+#             */
/*   Updated: 2024/09/17 17:44:51 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
{
    std::cout << "ClapTrap " << name << " has been created!" << std::endl;
    this->name = name;
    this->hitpoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
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
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
        std::cout << "ClapTrap " << this->name << " has " << this->hitpoints << " hitpoints left!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->hitpoints += amount;
    std::cout << "ClapTrap " << this->name << " has been repaired for " << amount << " hitpoints!" << std::endl;
    std::cout << "ClapTrap " << this->name << " has " << this->hitpoints << " hitpoints!" << std::endl;
}