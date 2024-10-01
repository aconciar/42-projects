/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:09:01 by andrea            #+#    #+#             */
/*   Updated: 2024/09/23 15:18:39 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") 
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const 
{
    std::cout << "Animal makes a sound..." << std::endl;
}

std::string Animal::getType() const 
{
    return (this->type);
}