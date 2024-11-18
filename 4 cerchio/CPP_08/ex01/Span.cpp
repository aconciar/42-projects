/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:13:03 by aconciar          #+#    #+#             */
/*   Updated: 2024/11/03 13:58:47 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) 
{
	if (this != &other)
	{
		this->maxSize = other.maxSize;
		this->numbers = other.numbers;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int value)
{
	if (numbers.size() >= maxSize)
	{
		throw (std::out_of_range("Vector is already full"));
	}
	// if (std::find(numbers.begin(), numbers.end(), value) != numbers.end())
		// return ;
	numbers.push_back(value);
}

template <typename InputIterator>
void	Span::addNumber(InputIterator begin, InputIterator end)
{
	if (numbers.size() + std::distance(begin, end) > maxSize)
	{
		throw (std::out_of_range("Vector is already full"));
	}
	numbers.insert(numbers.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (numbers.size() < 2)
	{
		throw (std::logic_error("2 numbers at least needed"));
	}
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	int	shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1;i++)
	{
		int tmp = sorted[i + 1] - sorted[i];
		if (tmp < shortest)
			shortest = tmp;
	}
	return (shortest);
}

int	Span::longestSpan()
{
	if (numbers.size() < 2)
	{
		throw (std::logic_error("2 numbers at least needed"));
	}
	int max = *std::max_element(numbers.begin(), numbers.end());
	int min = *std::min_element(numbers.begin(), numbers.end());
	return (max - min);
}
