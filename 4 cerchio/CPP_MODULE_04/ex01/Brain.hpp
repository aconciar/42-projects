/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:37:05 by andrea            #+#    #+#             */
/*   Updated: 2024/09/23 15:43:11 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    public :

        std::string ideas[100];
        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& other);
};

#endif