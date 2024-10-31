/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:26:08 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 18:51:34 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ZombieHorde.hpp"
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    ZombieHorde horde(5);
    horde.announce();
    return (0);
}