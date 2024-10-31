/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:28:15 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/16 17:19:16 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	// Test con MutantStack
	std::cout << "=== Test con MutantStack ===" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top element: " << mstack.top() << std::endl; // Dovrebbe stampare 17
	mstack.pop();
	
	std::cout << "Stack size after pop: " << mstack.size() << std::endl; // Dovrebbe stampare 1
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;  // Avanza l'iteratore
	--it;  // Torna indietro

	std::cout << "MutantStack elements:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;  // Stampa tutti gli elementi dello stack
		++it;
	}

	std::stack<int> s(mstack);  // Copia di MutantStack in uno std::stack

	// Test con std::list
	std::cout << "\n=== Test con std::list ===" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	
	std::cout << "Top element: " << lst.back() << std::endl; // Simile a std::stack::top()
	lst.pop_back();  // Simile a std::stack::pop()
	
	std::cout << "List size after pop: " << lst.size() << std::endl; // Dovrebbe stampare 1
	
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	++lit;  // Avanza l'iteratore
	--lit;  // Torna indietro

	std::cout << "List elements:" << std::endl;
	while (lit != lite) {
		std::cout << *lit << std::endl;  // Stampa tutti gli elementi della lista
		++lit;
	}

	return (0);
}
