/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:23:37 by andrea            #+#    #+#             */
/*   Updated: 2024/11/03 14:23:23 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    std::string input;

    for (int i = 1; i < argc; i++)
    {
        input += argv[i];
        if (i < argc - 1)
            input += " ";
    }
    PmergeMe pmergeMe(input);
    pmergeMe.FordjVector(input);
    // pmergeMe.PrintVector();
    return (0);
}