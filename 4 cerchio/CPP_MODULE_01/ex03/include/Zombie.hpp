/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:41:41 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 18:48:34 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
        Zombie() : _name("default"), _type("default") {};
        Zombie(std::string name, std::string type);
        ~Zombie();
        void    announce();
    
    private:
        std::string _name;
        std::string _type;
};

#endif