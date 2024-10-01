/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:16 by andrea            #+#    #+#             */
/*   Updated: 2024/09/17 17:18:50 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // Creazione di un ClapTrap
    ClapTrap claptrap1("CL4P-TP");

    // Esecuzione di alcune azioni
    claptrap1.attack("Bandit");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(3);
    claptrap1.attack("Psycho");
    claptrap1.takeDamage(10); // ClapTrap va a 0 hitpoints

    // ClapTrap non può più attaccare o ripararsi
    claptrap1.attack("Psycho");
    claptrap1.beRepaired(10);

    return 0;
}