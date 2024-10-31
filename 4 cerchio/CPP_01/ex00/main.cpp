/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:27:22 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/10 19:06:19 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() 
{
	Zombie* heapZombie;

	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	randomChump("StackZombie");
	delete (heapZombie);
	return (0);
}
