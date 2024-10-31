/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:21:24 by andrea            #+#    #+#             */
/*   Updated: 2024/10/14 14:41:21 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public :
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();
		Fixed &operator = (const Fixed &other);
		bool operator > (const Fixed &other) const;
		bool operator < (const Fixed &other) const;
		bool operator >= (const Fixed &other) const;
		bool operator <= (const Fixed &other) const;
		bool operator == (const Fixed &other) const;
		bool operator != (const Fixed &other) const;
		Fixed operator + (const Fixed &other) const;
		Fixed operator - (const Fixed &other) const;
		Fixed operator * (const Fixed &other) const;
		Fixed operator / (const Fixed &other) const;
		Fixed &operator ++ (void);
		Fixed operator ++ (int);
		Fixed &operator -- (void);
		Fixed operator -- (int);

		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

	private :
		int _value;
		static const int _fractionalBits = 8;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif