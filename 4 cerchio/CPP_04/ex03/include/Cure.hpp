/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:40:15 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 17:06:56 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(Cure const &other);
		Cure &operator=(Cure const &other);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif