/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:12:57 by aconciar          #+#    #+#             */
/*   Updated: 2024/11/03 13:53:11 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
	public :
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

		void	addNumber(int value);
		template <typename InputIterator>
		void	addNumber(InputIterator begin, InputIterator end);
		int		shortestSpan();
		int		longestSpan();

	private :
		size_t	maxSize;
		std::vector<int> numbers;
};

#endif
