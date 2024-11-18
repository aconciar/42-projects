/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:12:47 by aconciar          #+#    #+#             */
/*   Updated: 2024/11/03 13:59:12 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	try
	{
		std::srand(static_cast<unsigned int>(std::time(0)));
		Span largeSpan(10000);
		for (int i = 0; i < 10000; ++i)
		{
			largeSpan.addNumber(std::rand() % 100000);
		}
		std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}


// int main()
// {
// 	try
// 	{
// 		Span sp(10);
// 		std::vector<int> numbers = {1, 2, 3, 4, 5};
	
// 		sp.addNumber(numbers.begin(), numbers.end());
// 		sp.addNumber(10);
// 		sp.addNumber(20);
// 		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
// 		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
// 		std::vector<int> extraNumbers = {30, 40, 50};
// 		sp.addNumber(extraNumbers.begin(), extraNumbers.end());
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// 	return (0);
// }