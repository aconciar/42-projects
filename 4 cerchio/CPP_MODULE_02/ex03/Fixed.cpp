/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:30:33 by andrea            #+#    #+#             */
/*   Updated: 2024/09/10 17:50:32 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value)
{
    this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator = (const Fixed &other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

bool Fixed::operator > (const Fixed &other) const
{
    if (this->_value > other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator < (const Fixed &other) const
{
    if (this->_value < other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator >= (const Fixed &other) const
{
    if (this->_value >= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator <= (const Fixed &other) const
{
    if (this->_value <= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator == (const Fixed &other) const
{
    if (this->_value == other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator != (const Fixed &other) const
{
    if (this->_value != other.getRawBits())
        return (true);
    return (false);
}

Fixed Fixed::operator + (const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator - (const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator * (const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator / (const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator ++ (void)
{
    this->_value++;
    return (*this);
}

Fixed Fixed::operator ++ (int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed &Fixed::operator -- (void)
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator -- (int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

int Fixed::toInt(void) const
{
    return (this->_value >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << this->_fractionalBits));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}