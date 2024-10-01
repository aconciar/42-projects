/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:03:55 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 19:16:18 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Human.hpp"

Human::Human() {}

Human::~Human() {}

Brain const &Human::getBrain() const
{
    return (_brain);
}

std::string Human::identify() const
{
    return (_brain.identify());
}