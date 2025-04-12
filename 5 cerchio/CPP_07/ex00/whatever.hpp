/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:43:38 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/11 15:48:37 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >

void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template< typename T >

T	min(T &a, T &b)
{
	if (a < b)
		return (a);
	if (a > b)
		return (b);
	return (b);
}

template< typename T >

T	max(T &a, T &b)
{
	if (a > b)
		return (a);
	if (a < b)
		return (b);
	return (b);
}

#endif