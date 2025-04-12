/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:16:17 by aconciar          #+#    #+#             */
/*   Updated: 2024/11/03 12:11:51 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Intern.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main()
{
	Intern someRandomIntern;

	Bureaucrat john("John", 1);
	Bureaucrat bob("Bob", 50);
	Bureaucrat alice("Alice", 150);

	AForm* form = NULL;

	std::cout << "\nTest: Creazione di Robotomy Request Form\n";
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}

	std::cout << "\nTest: Creazione di Shrubbery Creation Form\n";
	form = someRandomIntern.makeForm("shrubbery creation", "home");
	if (form)
	{
		std::cout << *form << std::endl;
		alice.signForm(*form);
		john.signForm(*form);
		john.executeForm(*form);
		delete form;
	}

	std::cout << "\nTest: Creazione di Presidential Pardon Form\n";
	form = someRandomIntern.makeForm("presidential pardon", "Alice");
	if (form)
	{
		std::cout << *form << std::endl;

		john.signForm(*form);
		john.executeForm(*form);
		delete form;
	}

	std::cout << "\nTest: Tentativo di creare un form inesistente\n";
	form = someRandomIntern.makeForm("invalid form", "target");
	if (form)
		delete form;
	return (0);
}
