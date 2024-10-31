/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:16 by andrea            #+#    #+#             */
/*   Updated: 2024/10/15 18:39:41 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/DiamondTrap.hpp"

int main()
{
	DiamondTrap diamondtrap1("D1AM0ND");
	DiamondTrap diamondtrap2(diamondtrap1);
	DiamondTrap diamondtrap3;

	// Test DiamondTrap
	diamondtrap3.attack("Final Boss");
	diamondtrap3.takeDamage(80);
	diamondtrap3.beRepaired(50);
	diamondtrap3.whoAmI();

	return (0);
}


