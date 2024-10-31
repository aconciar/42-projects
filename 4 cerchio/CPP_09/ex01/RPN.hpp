/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:18:06 by andrea            #+#    #+#             */
/*   Updated: 2024/10/19 21:30:59 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <sstream>

class RPN
{
    public:
        RPN();
        RPN(const std::string &str);
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        ~RPN();
        void printStack();
    
    private:
        void handleDigit(const std::string &str);
        void handleOperator(const std::string &str);
        void run(const std::string &str);
        std::stack<int> stack;
};

#endif