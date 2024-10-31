/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:16:17 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/09 15:35:39 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        // Creazione di alcuni Bureaucrat con gradi diversi
        Bureaucrat john("John", 1);
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 150);

        // Test: Creazione e firma di ShrubberyCreationForm
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;

        alice.signForm(shrubbery);  // Alice non può firmare (grado troppo basso)
        bob.signForm(shrubbery);   // Bob può firmare
        std::cout << shrubbery << std::endl;

        // Test: Esecuzione di ShrubberyCreationForm
        alice.executeForm(shrubbery);  // Alice non può eseguire (grado troppo basso)
        john.executeForm(shrubbery); // John può eseguire

        // Test: Creazione, firma ed esecuzione di RobotomyRequestForm
        RobotomyRequestForm robotomy("Target");
        std::cout << robotomy << std::endl;

        bob.signForm(robotomy);    // Bob può firmare (grado 50 è sufficiente)
        bob.executeForm(robotomy); // Bob può eseguire (esito 50% successo/fallimento)

        // Test: Creazione, firma ed esecuzione di PresidentialPardonForm
        PresidentialPardonForm pardon("Alice");
        std::cout << pardon << std::endl;

        john.signForm(pardon);   // John può firmare (grado 1 è sufficiente)
        john.executeForm(pardon); // John può eseguire (grado 1 è sufficiente)

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}


