/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:25:48 by andrea            #+#    #+#             */
/*   Updated: 2024/09/17 17:03:49 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(const Point& a, const Point& b, const Point& c)
{
	float   x1;
    float   y1;
	float   x2;
    float   y2;
	float   x3;
    float   y3;

	x1 = a.getX().toFloat();
	y1 = a.getY().toFloat();
	x2 = b.getX().toFloat();
	y2 = b.getY().toFloat();
	x3 = c.getX().toFloat();
	y3 = c.getY().toFloat();

	return (x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0;
}

bool	bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
	float   A = area(a, b, c);
	float   A1 = area(point, b, c);
	float   A2 = area(a, point, c);
	float   A3 = area(a, b, point);

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return (false);
	else if (A == A1 + A2 + A3)
        return (true);
    return (false);
}