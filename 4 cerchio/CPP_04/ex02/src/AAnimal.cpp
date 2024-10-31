/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:46:48 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/16 16:51:01 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : type("default") 
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal() 
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() 
{
	return (this->type);
}