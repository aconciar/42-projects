/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:09:08 by andrea            #+#    #+#             */
/*   Updated: 2024/09/23 15:15:48 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    public :
        Animal();
        virtual ~Animal();
        virtual void makeSound() const;
        virtual std::string getType() const;

    protected :
        std::string type;
};

#endif