/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:18:45 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:54:38 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal() 
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(), brain(new Brain(*other.brain))
{
	this->type = other.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) 
{
	if (this != &other)
	{
		delete (this->brain);
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog() 
{
	delete (this->brain);
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const 
{
	std::cout << "Woof! Woof!" << std::endl;
}

std::string Dog::getIdea(int i) const
{
	return (this->brain->getIdea(i));
}

void Dog::setBrainIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}
