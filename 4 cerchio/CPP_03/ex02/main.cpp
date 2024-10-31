/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:16 by andrea            #+#    #+#             */
/*   Updated: 2024/10/15 16:02:36 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

int main()
{
	ClapTrap claptrap1("CL4P-TP");
	ScavTrap scavtrap1("SC4V-TP");
	FragTrap fragtrap1("FR4G-TP");
	FragTrap fragtrap2(fragtrap1);
	FragTrap fragtrap3;

	// Test ClapTrap
	claptrap1.attack("Bandit");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(3);

	// Test ScavTrap
	scavtrap1.attack("Psycho");
	scavtrap1.takeDamage(30);
	scavtrap1.beRepaired(20);
	scavtrap1.guardGate();

	// Test FragTrap
	fragtrap3.attack("Boss");
	fragtrap3.takeDamage(50);
	fragtrap3.beRepaired(40);
	fragtrap3.highFivesGuys();

	return (0);
}

