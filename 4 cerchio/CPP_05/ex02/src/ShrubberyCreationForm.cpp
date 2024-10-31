/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:40:34 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/09 15:30:38 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to open file " + filename);
	file << "      /\\      \n"
			"     /\\*\\     \n"
			"    /\\O\\*\\    \n"
			"   /*/\\/\\/\\   \n"
			"  /\\O\\/\\*\\/\\  \n"
			" /\\*\\/\\*\\/\\/\\ \n"
			"/\\O\\/\\/*/\\/O/\\\n"
			"      ||      \n"
			"      ||      \n"
			"      ||      \n";
	file.close();
}