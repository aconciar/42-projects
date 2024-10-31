/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:16:17 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/09 16:08:46 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Intern.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main() {
    // Creazione di un intern
    Intern someRandomIntern;

    // Creazione di alcuni Bureaucrat per firmare ed eseguire i form
    Bureaucrat john("John", 1);
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 150);

    AForm* form = NULL;

    // Test della creazione di "Robotomy Request"
    std::cout << "\nTest: Creazione di Robotomy Request Form\n";
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;

        // Firma e esecuzione del form
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    // Test della creazione di "Shrubbery Creation"
    std::cout << "\nTest: Creazione di Shrubbery Creation Form\n";
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form) {
        std::cout << *form << std::endl;

        // Firma e esecuzione del form
        alice.signForm(*form);  // Alice non può firmare
        john.signForm(*form);   // John può firmare
        john.executeForm(*form);  // John può eseguire
        delete form;
    }

    // Test della creazione di "Presidential Pardon"
    std::cout << "\nTest: Creazione di Presidential Pardon Form\n";
    form = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (form) {
        std::cout << *form << std::endl;

        // Firma e esecuzione del form
        john.signForm(*form);
        john.executeForm(*form);
        delete form;
    }

    // Test con un form inesistente
    std::cout << "\nTest: Tentativo di creare un form inesistente\n";
    form = someRandomIntern.makeForm("invalid form", "target");
    if (form) {
        delete form;
    }

    return 0;
}
