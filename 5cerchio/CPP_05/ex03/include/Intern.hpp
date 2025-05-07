/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:37:58 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/09 16:03:20 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);
		AForm *makeForm(const std::string &name, const std::string &target);

	private:
		AForm* createShrubberyCreationForm(const std::string &target);
		AForm* createRobotomyRequestForm(const std::string &target);
		AForm* createPresidentialPardonForm(const std::string &target);
};

#endif