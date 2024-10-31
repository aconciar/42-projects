/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:27:48 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 17:16:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Character.hpp"
#include "include/MateriaSource.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"

int main()
{
	std::cout << "Creating MateriaSource..." << std::endl;
	IMateriaSource* src = new MateriaSource();

	std::cout << "Learning new Materia (Ice and Cure)..." << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "Creating Character \"me\"..." << std::endl;
	ICharacter* me = new Character("me");

	AMateria* tmp;

	std::cout << "Creating and equipping Ice..." << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << "Creating and equipping Cure..." << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << "Creating Character \"bob\"..." << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << "Using Ice on bob..." << std::endl;
	me->use(0, *bob);

	std::cout << "Using Cure on bob..." << std::endl;
	me->use(1, *bob);

	std::cout << "Using non-existing Materia (index 2)..." << std::endl;
	me->use(2, *bob);

	std::cout << "Trying to equip more than 4 Materia..." << std::endl;
	AMateria* extraMateria1 = src->createMateria("ice");
	AMateria* extraMateria2 = src->createMateria("cure");
	AMateria* extraMateria3 = src->createMateria("ice");
	AMateria* extraMateria4 = src->createMateria("cure");

	me->equip(extraMateria1);
	me->equip(extraMateria2);
	me->equip(extraMateria3);
	me->equip(extraMateria4);

	delete (extraMateria3);
	delete (extraMateria4);

	std::cout << "Unequipping and re-equipping Materia..." << std::endl;
	Character* concreteMe = dynamic_cast<Character*>(me);
	if (concreteMe)
	{
		std::cout << "Unequipping Materia from slot 1..." << std::endl;
		AMateria* tmpToRemove = concreteMe->getMateria(1);
		concreteMe->unequip(1);
		if (tmpToRemove)
			delete (tmpToRemove);
	}
	else 
	{
		std::cerr << "Failed to cast ICharacter* to Character*." << std::endl; 
	}
	me->use(1, *bob);

	std::cout << "Re-equipping a new Cure Materia in slot 1..." << std::endl;
	me->equip(src->createMateria("cure"));
	me->use(1, *bob); 

	std::cout << "Testing deep copy of Character..." << std::endl;
	Character* copyMe = new Character(*dynamic_cast<Character*>(me));
	std::cout << "Using Ice on bob from copied character..." << std::endl;
	copyMe->use(0, *bob);

	std::cout << "Deleting characters and MateriaSource..." << std::endl;
	delete (bob);
	delete (me);
	delete (copyMe);
	delete (src);

	return (0);
}
