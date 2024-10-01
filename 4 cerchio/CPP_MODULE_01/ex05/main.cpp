/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:02:04 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 19:06:09 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Human.hpp"
#include <iostream>

int main()
{
    Human   bob;

    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
}