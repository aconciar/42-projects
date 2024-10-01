/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:41:52 by andrea            #+#    #+#             */
/*   Updated: 2024/09/02 22:54:44 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <iostream>

class ZombieEvent
{
    public:

        void    setZombieType(std::string type);
        Zombie* newZombie(std::string name);
        void randomChump();
    
    private:
        std::string _type;
};

#endif