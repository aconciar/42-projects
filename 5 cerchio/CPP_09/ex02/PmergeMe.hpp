/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:24:13 by andrea            #+#    #+#             */
/*   Updated: 2024/11/07 16:00:47 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib> 
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();

		void    FordjVector(std::vector<int> &vector);
		void    FordjDeque(std::deque<int> &deque);
};

#endif