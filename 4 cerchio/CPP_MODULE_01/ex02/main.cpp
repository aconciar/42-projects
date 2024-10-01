/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:41:59 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 18:53:17 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"
#include "include/ZombieEvent.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	main()
{
	Zombie		Bob("Bob", "Walker");
	Zombie		*Gary;
	ZombieEvent	event;

	srand(static_cast<unsigned int>(time(0)));
	std::cout << "\nLet's create Zombies on heap!" << std::endl;
    Bob.announce();

	std::cout << "\nI just created Zombies on stack!" << std::endl;
    
    event.setZombieType("Deadhead");
	Gary = event.newZombie("Gary");
    Gary->announce();
	delete (Gary);

    std::cout << "\nI just created Random Zombie!" << std::endl;
	event.setZombieType("Biter");
	event.randomChump();

	std::cout << std::endl;
}
