/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:20:27 by andrea            #+#    #+#             */
/*   Updated: 2024/09/02 22:24:43 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>
#include <string>

class Pony
{
    public:
        Pony(std::string name, int age, std::string color);
        ~Pony();
        void    sayHello();

    private:
        std::string _name;
        int         _age;
        std::string _color;
};

#endif