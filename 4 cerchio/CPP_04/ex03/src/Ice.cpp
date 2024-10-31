/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:38:15 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 17:09:16 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &other) : AMateria(other._type) {}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
