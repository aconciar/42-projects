/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:14:38 by andrea            #+#    #+#             */
/*   Updated: 2024/09/17 16:44:55 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point 
{
    public :
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        ~Point();
        Point &operator = (const Point &other);
        const Fixed&    getX(void) const;
        const Fixed&    getY(void) const;
    
    private :
        Fixed const _x;
        Fixed const _y;
};


#endif