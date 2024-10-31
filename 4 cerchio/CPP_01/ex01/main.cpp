/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:45:15 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/01 16:02:57 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 5;
    std::string name = "HordeZombie";

    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; ++i)
        horde[i].announce();
    delete[] (horde);
    return (0);
}
