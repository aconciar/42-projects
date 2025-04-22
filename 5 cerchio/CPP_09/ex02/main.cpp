/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:23:37 by andrea            #+#    #+#             */
/*   Updated: 2024/11/07 16:15:35 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input provided" << std::endl;
		return (1);
	}

	if ((argc - 1) % 2 != 0 && std::atoi(argv[argc - 1]) < 0)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::vector<int> vector;
	for (int i = 1; i < argc; i++)
	{
		int value = std::atoi(argv[i]);
		if (value < 0)
		{
			std::cerr << "Error: Negative values are not allowed" << std::endl;
			return (1);
		}
		vector.push_back(value);
	}

	PmergeMe pmerge;
	pmerge.FordjVector(vector);

	std::deque<int>	deque;

	for (int i = 1; i < argc; i++)
	{
		int value = std::atoi(argv[i]);
		deque.push_back(value);
	}

	pmerge.FordjDeque(deque);
	return (0);
}