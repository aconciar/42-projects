/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:16:17 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/07 16:48:18 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Form.hpp"
#include "include/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;
        try
        {
            Bureaucrat alice("Alice", 151);
        }
        catch (std::exception& e)
        {
            std::cerr << "Failed to create Alice: " << e.what() << std::endl;
        }
        try
        {
            Bureaucrat bob("Bob", 0);
        }
        catch (std::exception& e)
        {
            std::cerr << "Failed to create Bob: " << e.what() << std::endl;
        }
        Form taxForm("Tax Form", 5, 10);
        std::cout << taxForm << std::endl;
        try
        {
            Form invalidForm("Invalid Form", 151, 10);
        }
        catch (std::exception& e)
        {
            std::cerr << "Failed to create Invalid Form: " << e.what() << std::endl;
        }

        std::cout << "\nJohn is trying to sign the Tax Form:" << std::endl;
        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat jim("Jim", 6);
        std::cout << "\nJim is trying to sign the Tax Form:" << std::endl;
        jim.signForm(taxForm);
        std::cout << taxForm << std::endl;

        std::cout << "\nJim tries to improve his grade and sign the form again:" << std::endl;
        jim.incrementGrade();
        jim.signForm(taxForm);
        std::cout << taxForm << std::endl;

        std::cout << "\nJohn tries to decrement his grade beyond the limit:" << std::endl;
        try
        {
            john.decrementGrade();
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

    }
    catch (std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return (0);
}

