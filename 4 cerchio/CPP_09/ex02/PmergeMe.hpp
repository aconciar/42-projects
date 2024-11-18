/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:24:13 by andrea            #+#    #+#             */
/*   Updated: 2024/11/03 14:24:24 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#include <cstdlib> 

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const std::string &input);
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();

        void    FordjVector(const std::string &input);
        void    FordjDeque(const std::string &input);
        void    PrintVector();
    private:
        std::string         input;
        std::vector<int>    vector;
        std::deque<int>     deque;
};

#endif