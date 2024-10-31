/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:41:52 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 18:40:02 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

class ZombieHorde
{
    public:
        ZombieHorde(int n);
        ~ZombieHorde();
        void    announce();
    
    private:
        int     _n;
        Zombie  *_zombies;
};

#endif