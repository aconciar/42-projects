/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:24:03 by andrea            #+#    #+#             */
/*   Updated: 2024/11/03 14:27:32 by andrea           ###   ########.fr       */
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

static bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	return (a.first < b.first);
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
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vector.size(); i += 2)
	{
		int first = vector[i];
		int second = (i + 1 < vector.size()) ? vector[i + 1] : first;
		if (first > second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}
	std::sort(pairs.begin(), pairs.end(), comparePairs);

        // Visualizzazione delle coppie ordinate
        std::cout << "Coppie ordinate: ";
        for (size_t i = 0; i < pairs.size(); ++i) {
            std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
        }
        std::cout << std::endl;

        // Merge finale dei secondi elementi in ordine crescente
        std::vector<int> sorted_result;
        for (size_t i = 0; i < pairs.size(); ++i) {
            sorted_result.push_back(pairs[i].first);
            sorted_result.push_back(pairs[i].second);
        }

        // Visualizzazione del risultato finale
        std::cout << "Vettore ordinato: ";
        for (size_t i = 0; i < sorted_result.size(); ++i) {
            std::cout << sorted_result[i] << " ";
        }
        std::cout << std::endl;
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