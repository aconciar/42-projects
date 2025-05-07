/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:10:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/14 16:25:08 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other) : _array(new T[other._size]), _size(other._size) {}

template <typename T>
Array<T>& Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		delete[] _array;
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw (OutOfLimitsException());
	return (_array[n]);
}

template <typename T>
unsigned int Array<T>:: size() const
{
	return (_size);
}
