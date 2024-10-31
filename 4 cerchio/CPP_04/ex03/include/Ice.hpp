/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:36:31 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 17:09:05 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif