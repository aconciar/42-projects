/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:20:12 by andrea            #+#    #+#             */
/*   Updated: 2024/09/02 22:26:23 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, int age, std::string color) : _name(name), _age(age), _color(color)
{
    std::cout << "Pony " << _name << " is born" << std::endl;
}

Pony::~Pony()
{
    std::cout << "Pony " << _name << " is dead" << std::endl;
}

void    Pony::sayHello()
{
    std::cout << "Hello! I'm " << _name << ", I'm " << _age << " years old and I'm " << _color << std::endl;
}