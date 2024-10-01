/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:21:24 by andrea            #+#    #+#             */
/*   Updated: 2024/09/09 16:31:14 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public :
        Fixed();
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator = (const Fixed &other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private :
        int _value;
        static const int _fractionalBits = 8;
};

#endif