/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:44:00 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/16 17:10:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

Character::Character(Character const &other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

Character &Character::operator=(Character const &other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _materias[idx])
		_materias[idx]->use(target);
}

AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (_materias[idx]);
	return (NULL);
}