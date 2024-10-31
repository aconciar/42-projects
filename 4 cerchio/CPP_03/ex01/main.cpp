/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:16 by andrea            #+#    #+#             */
/*   Updated: 2024/10/15 15:55:15 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"

int main()
{
	ClapTrap claptrap1("CL4P-TP");
	ScavTrap scavtrap1("SC4V-TP");
	ScavTrap scavtrap2(scavtrap1);

	// Test ClapTrap
	claptrap1.attack("Bandit");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(3);

	// Test ScavTrap
	scavtrap2.attack("Psycho");
	scavtrap2.takeDamage(30);
	scavtrap2.beRepaired(20);
	scavtrap2.guardGate();

	return 0;
}
