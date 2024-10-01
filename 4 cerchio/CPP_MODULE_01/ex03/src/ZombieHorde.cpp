/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:26:49 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 18:46:04 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ZombieHorde.hpp"

std::string randomName()
{
    std::string names[7] = {"Bob", "Alice", "John", "Eve", "Charlie", "Andrea", "Alessia"};
    std::string name;

    name = names[rand() % 7];
    return (name);
}

ZombieHorde::ZombieHorde(int n) : _n(n)
{

    if (n < 0)
        std::cout << "Invalid number of zombies" << std::endl;
    else
    {
        _zombies = new Zombie[n];
        int i = 0;
        while (i < n)
        {
            std::string name = randomName();
            _zombies[i] = Zombie(name, "Horde");
            i++;
        }
    }
}

ZombieHorde::~ZombieHorde()
{
    delete[] _zombies;
}

void ZombieHorde::announce()
{
    int i = 0;
    while (i < _n)
    {
        _zombies[i].announce();
        i++;
    }
}