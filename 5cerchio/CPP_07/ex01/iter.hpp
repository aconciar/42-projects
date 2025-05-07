/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:35:59 by aconciar          #+#    #+#             */
/*   Updated: 2024/11/03 12:29:26 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T>

void	iter(T *array, size_t size, void (*f)(T &))
{
	if (array == NULL || f == NULL)
		return;
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif