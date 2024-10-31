/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:04:54 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 19:12:01 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain
{
    public:
        Brain();
        ~Brain();
        std::string identify() const;
};

#endif