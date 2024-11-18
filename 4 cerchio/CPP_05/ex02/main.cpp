/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:16:17 by aconciar          #+#    #+#             */
/*   Updated: 2024/11/03 12:01:56 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat john("John", 1);
		Bureaucrat bob("Bob", 50);
		Bureaucrat alice("Alice", 150);

		ShrubberyCreationForm shrubbery("home");
		std::cout << shrubbery << std::endl;

		alice.signForm(shrubbery);
		bob.signForm(shrubbery);
		std::cout << shrubbery << std::endl;

		alice.executeForm(shrubbery);
		john.executeForm(shrubbery);

		RobotomyRequestForm robotomy("Target");
		std::cout << robotomy << std::endl;

		bob.signForm(robotomy);
		bob.executeForm(robotomy);
		PresidentialPardonForm pardon("Alice");
		std::cout << pardon << std::endl;

		john.signForm(pardon);
		john.executeForm(pardon);

	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}


