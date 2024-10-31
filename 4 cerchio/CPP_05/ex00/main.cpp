/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:16:17 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/07 15:53:40 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("John", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.incrementGrade();  // Questo lancerà un'eccezione
    } 
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Anna", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;

        b2.decrementGrade();  // Questo lancerà un'eccezione
    } 
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
