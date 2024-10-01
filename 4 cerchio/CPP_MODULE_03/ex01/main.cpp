/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:16 by andrea            #+#    #+#             */
/*   Updated: 2024/09/17 17:42:19 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap claptrap1("CL4P-TP");
    ScavTrap scavtrap1("SC4V-TP");

    // Test ClapTrap
    claptrap1.attack("Bandit");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(3);

    // Test ScavTrap
    scavtrap1.attack("Psycho");
    scavtrap1.takeDamage(30);
    scavtrap1.beRepaired(20);
    scavtrap1.guardGate();

    return 0;
}
