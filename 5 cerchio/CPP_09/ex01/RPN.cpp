/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:18:13 by andrea            #+#    #+#             */
/*   Updated: 2024/10/19 21:34:29 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &str)
{
	run(str);
}

RPN::RPN(RPN const &other) : stack(other.stack) {}

RPN &RPN::operator=(RPN const &other)
{
    if (this != &other)
        stack = other.stack;
    return (*this);
}

RPN::~RPN() {}

void    RPN::handleDigit(const std::string &str)
{
    int digit = str[0] - '0';
    stack.push(digit);
}

void    RPN::handleOperator(const std::string &str)
{
    if (stack.size() < 2)
        throw std::runtime_error("Error");
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    int result = 0;
    if (str[0] == '+')
        result = b + a;
    else if (str[0] == '-')
        result = b - a;
    else if (str[0] == '*')
        result = b * a;
    else if (str[0] == '/')
    {
        if (a == 0)
            throw std::runtime_error("Error");
        result = b / a;
    }
    stack.push(result);
}

void RPN::run(const std::string &str)
{
    std::istringstream iss(str);
    std::string token;

    try
    {
        while (std::getline(iss, token, ' '))
        {
            if (isdigit(token[0]))
                handleDigit(token);
            else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
                handleOperator(token);
            else
                throw std::runtime_error("Error");
        }
        if (stack.size() != 1)
            throw std::runtime_error("Error");
        else
            std::cout << stack.top() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void RPN::printStack()
{
    while (!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}
