/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:37:36 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/09 16:09:34 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}


AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(Intern::*formCreators[3])(const std::string &target) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}
	std::cout << "Intern cannot create " << name << " form" << std::endl;
	return (NULL);
}