/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:09:08 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:55:26 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	public :
		AAnimal();
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		virtual std::string getType();
	
	protected :
		std::string type;
};

#endif