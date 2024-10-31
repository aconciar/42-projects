/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:42:41 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/11 15:39:50 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base::~Base() {}

Base	*generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	int random = std::rand() % 3;

	if (random == 0)
	{
		std::cout << "Generated A" << std::endl;
		return (new A());
	}
	else if (random == 1)
	{
		std::cout << "Generated B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "Generated C" << std::endl;
		return (new C());
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Unknown" << std::endl;
	}	
}

void	identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type: A" << std::endl;
		return ;
	}
	catch (std::exception&) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type: B" << std::endl;
		return ;
	}
	catch (std::exception&) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type: C" << std::endl;
		return ;
	}
	catch (std::exception&) {}
    std::cout << "Unknown type" << std::endl;
}