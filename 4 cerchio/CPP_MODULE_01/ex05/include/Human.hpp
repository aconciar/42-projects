/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:04:48 by andrea            #+#    #+#             */
/*   Updated: 2024/09/05 19:14:55 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
    public:
        Human();
        ~Human();
        const Brain &getBrain() const;
        std::string identify() const;

    private:
        Brain const _brain;
};

#endif