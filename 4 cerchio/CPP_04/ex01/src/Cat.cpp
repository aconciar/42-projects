/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:19:29 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:54:33 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal() 
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(), brain(new Brain(*other.brain))
{
	this->type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
	if (this != &other)
	{
		delete (this->brain);
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat() 
{
	delete (this->brain);
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
	std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setBrainIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}

std::string Cat::getBrainIdea(int i) const
{
	return (this->brain->getIdea(i));
}