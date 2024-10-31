/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:18:45 by andrea            #+#    #+#             */
/*   Updated: 2024/10/21 15:18:49 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal() 
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
	this->type = other.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) 
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog() 
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const 
{
	std::cout << "Woof! Woof!" << std::endl;
}
