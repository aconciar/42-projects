/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:46:49 by andrea            #+#    #+#             */
/*   Updated: 2024/09/02 23:27:41 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ZombieEvent.hpp"
#include <cstdlib>

void    ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    return (new Zombie(name, this->_type));
}

void ZombieEvent::randomChump()
{
    std::string names[7] = {"Bob", "Alice", "John", "Eve", "Charlie", "Andrea", "Alessia"};
    std::string name;

    name = names[rand() % 7];
    Zombie zombie = Zombie(name, this->_type);
    zombie.announce();
}
