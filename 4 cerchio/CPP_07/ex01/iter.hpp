/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:35:59 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/11 16:53:55 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T>

void	iter(T *array, size_t size, void (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif