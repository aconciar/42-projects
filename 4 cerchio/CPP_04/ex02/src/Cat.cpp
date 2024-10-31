/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:19:29 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:55:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : AAnimal() 
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal()
{
	this->type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat() 
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
	std::cout << "Meow! Meow!" << std::endl;
}
