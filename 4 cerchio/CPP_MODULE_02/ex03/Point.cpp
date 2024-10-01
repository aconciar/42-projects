/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:56:24 by andrea            #+#    #+#             */
/*   Updated: 2024/09/17 16:38:10 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &other)
{
    *this = other;
}

Point::~Point() {}

Point &Point::operator = (const Point&)
{
    return (*this);
}

const Fixed&    Point::getX(void) const
{
    return (this->_x);
}

const Fixed&    Point::getY(void) const
{
    return (this->_y);
}