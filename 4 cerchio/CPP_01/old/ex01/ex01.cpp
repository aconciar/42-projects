/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:36:07 by andrea            #+#    #+#             */
/*   Updated: 2024/09/02 22:41:08 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    memoryLeak()
{
    std::string* panther = new std::string("String panther");
    std::cout << *panther << std::endl;
    delete (panther);
}

int main()
{
    memoryLeak();
    return (0);
}