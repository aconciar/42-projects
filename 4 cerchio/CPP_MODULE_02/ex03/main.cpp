/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:20:57 by andrea            #+#    #+#             */
/*   Updated: 2024/09/17 17:03:22 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int bsp(const Point &a, const Point &b, const Point &c, const Point &point);

int main( void ) 
{
	Point		A(0, 0);
	Point		B(5, 0);
	Point		C(0, 5);
	Point		P(1, 1);

	if (bsp(A, B, C, P) == true)
    	std::cout << "Point P is in the triangle ABC!" << std::endl;
    else
		std::cout << "Point P is not in the triangle ABC!" << std::endl;
	return 0;
}
