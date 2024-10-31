/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:45:10 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 17:06:15 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public :
		Character();
		Character(std::string const & name);
		Character(Character const & other);
		Character & operator=(Character const & other);
		~Character();
		std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		AMateria* getMateria(int idx) const;

	private:
		std::string _name;
		AMateria* _materias[4];
};

#endif