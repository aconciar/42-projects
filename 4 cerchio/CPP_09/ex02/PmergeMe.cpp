/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:24:03 by andrea            #+#    #+#             */
/*   Updated: 2024/10/22 15:56:10 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : input(""), vector(), deque() {}

PmergeMe::PmergeMe(const std::string &input) : input(input), vector(), deque() {}

PmergeMe::PmergeMe(PmergeMe const &other) : input(other.input), vector(other.vector), deque(other.deque) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		input = other.input;
		vector = other.vector;
		deque = other.deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool    isNumber(const std::string &input)
{
	if (input.empty())
		return (false);
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

void    print(const std::vector<int> &vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];
		if (i + 1 < vector.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void    PmergeMe::FordjVector(const std::string &input)
{
	std::stringstream	ss(input);
	std::string			str;
	int					value;

	while (std::getline(ss, str, ' '))
	{
		if (isNumber(str))
		{
			value = atoi(str.c_str());
			vector.push_back(value);
		}
		else
		{
			std::cout << "Error: " << str << " is not a number" << std::endl;
			return ;
		}
	}
	for (size_t i = 0; i < vector.size(); i += 2)
	{
		if (vector[i] > vector[i + 1])
		{
			int tmp = vector[i];
			vector[i] = vector[i + 1];
			vector[i + 1] = tmp;
		}
	}
	
}

void    PmergeMe::FordjDeque(const std::string &input)
{
	std::stringstream	ss(input);
	std::string			str;
	int					value;

	while (std::getline(ss, str, ' '))
	{
		if (isNumber(str))
		{
			value = atoi(str.c_str());
			deque.push_back(value);
		}
		else
		{
			std::cout << "Error: " << input << " is not a number" << std::endl;
			return ;
		}
	}
}

void    PmergeMe::PrintVector()
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];
		if (i + 1 < vector.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}