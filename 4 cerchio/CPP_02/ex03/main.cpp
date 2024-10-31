/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:20:57 by andrea            #+#    #+#             */
/*   Updated: 2024/10/14 15:35:23 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int bsp(const Point a, const Point b, const Point c, const Point point);

int main( void ) 
{
	Point		A(0.0f, 0.0f);
	Point		B(5.0f, 0.0f);
	Point		C(0.0f, 5.0f);
	Point		P1(1.0f, 1.0f);
	Point		P2(6.0f, 1.0f);
	Point		P3(0.0f, 0.0f);
	Point		P4(2.5f, 0.0f);

	if (bsp(A, B, C, P1) == true)
    	std::cout << "Point P1 is in the triangle ABC!" << std::endl;
    else
		std::cout << "Point P1 is not in the triangle ABC!" << std::endl;
	
	if (bsp(A, B, C, P2) == true)
		std::cout << "Point P2 is in the triangle ABC!" << std::endl;
	else
		std::cout << "Point P2 is not in the triangle ABC!" << std::endl;

	if (bsp(A, B, C, P3) == true)
		std::cout << "Point P3 is in the triangle ABC!" << std::endl;
	else
		std::cout << "Point P3 is not in the triangle ABC!" << std::endl;
	
	if (bsp(A, B, C, P4) == true)
		std::cout << "Point P4 is in the triangle ABC!" << std::endl;
	else
		std::cout << "Point P4 is not in the triangle ABC!" << std::endl;

	return (0);
}
