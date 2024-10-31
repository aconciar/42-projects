/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:06:16 by andrea            #+#    #+#             */
/*   Updated: 2024/10/15 15:38:22 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap1("CL4P-TP");

	claptrap1.attack("Bandit");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(3);
	claptrap1.attack("Psycho");
	claptrap1.takeDamage(10);
	claptrap1.attack("Psycho");
	claptrap1.beRepaired(10);
	return (0);
}