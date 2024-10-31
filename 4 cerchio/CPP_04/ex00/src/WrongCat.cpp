/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:30:21 by andrea            #+#    #+#             */
/*   Updated: 2024/10/21 15:19:08 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() 
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	this->type = other.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) 
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const 
{
	std::cout << "Wrong Meow!" << std::endl;
}