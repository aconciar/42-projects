/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:16 by andrea            #+#    #+#             */
/*   Updated: 2024/09/18 18:42:42 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    ClapTrap claptrap1("CL4P-TP");
    ScavTrap scavtrap1("SC4V-TP");
    FragTrap fragtrap1("FR4G-TP");
    DiamondTrap diamondtrap1("D1AM0ND");

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
    fragtrap1.attack("Boss");
    fragtrap1.takeDamage(50);
    fragtrap1.beRepaired(40);
    fragtrap1.highFivesGuys();

    // Test DiamondTrap
    diamondtrap1.attack("Final Boss");
    diamondtrap1.takeDamage(80);
    diamondtrap1.beRepaired(50);
    diamondtrap1.whoAmI();

    return 0;
}


