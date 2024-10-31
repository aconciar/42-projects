/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:43:21 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:54:23 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
}