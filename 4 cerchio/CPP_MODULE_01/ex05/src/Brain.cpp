/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:03:36 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 12:43:15 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() {}

Brain::~Brain() {}

std::string Brain::identify() const
{
    std::stringstream address;

    address << this;
    return (address.str());
}
