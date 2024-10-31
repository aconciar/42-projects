/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:36:01 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/11 16:56:05 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(int &value)
{
    std::cout << value << " ";
}

void incrementInt(int &value)
{
    value++;
}

void printString(std::string &str)
{
    std::cout << str << " ";
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original integer array: ";
    iter(intArray, intArrayLength, printInt);
    std::cout << std::endl;

    iter(intArray, intArrayLength, incrementInt);
    std::cout << "Incremented integer array: ";
    iter(intArray, intArrayLength, printInt);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "world", "this", "is", "iter"};
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strArrayLength, printString);
    std::cout << std::endl;

    return 0;
}