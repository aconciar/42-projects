/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:57:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/15 18:44:44 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>

class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		~Array();
		Array &operator=(Array const &other);
		T &operator[](unsigned int n);
		unsigned int size() const;
		class OutOfLimitsException : public std::exception {
		public:
	   		virtual const char* what() const throw() {
				return ("Index out of limits!");
		}
	};

	private:
		T *_array;
		unsigned int _size;
		
};

#include "Array.tpp"

#endif