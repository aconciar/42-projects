/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:46:38 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/11 15:38:23 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    Base* base = generate();

    std::cout << "Identify by pointer:" << std::endl;
    identify(base);
    std::cout << "Identify by reference:" << std::endl;
    identify(*base);
    delete (base);
    return (0);
}
