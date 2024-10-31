/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:25:16 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/07 19:05:18 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	public :
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public :
				const char* what() const throw();
		};

	private :
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	
	friend std::ostream& operator<<(std::ostream& os, const AForm& form);
};

#endif