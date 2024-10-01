/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:20:02 by andrea            #+#    #+#             */
/*   Updated: 2024/09/02 22:27:45 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void    ponyOnTheHeap()
{
    Pony *pony = new Pony("Heap", 5, "black");
    pony->sayHello();
    delete (pony);
}

void    ponyOnTheStack()
{
    Pony pony = Pony("Stack", 3, "white");
    pony.sayHello();
}

int main()
{
    std::cout << "Creating a pony on the heap" << std::endl;
    ponyOnTheHeap();
    std::cout << std::endl;
    std::cout << "Creating a pony on the stack" << std::endl;
    ponyOnTheStack();
    return (0);
}