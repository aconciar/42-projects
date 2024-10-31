/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:09:01 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:54:17 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : type("Animal") 
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) 
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) 
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
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