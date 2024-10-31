/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:40:22 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 17:08:48 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria(other._type) {}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
