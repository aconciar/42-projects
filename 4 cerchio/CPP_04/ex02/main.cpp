/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:08:26 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:58:33 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/AAnimal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"

int main()
{
	// AAnimal aAnimal;

	std::cout << "---- Creazione di un oggetto Cat ----" << std::endl;
	Cat cat;
	std::cout << "Il tipo di cat è: " << cat.getType() << std::endl;
	cat.makeSound();

	std::cout << "---- Creazione di un oggetto Dog ----" << std::endl;
	Dog dog;
	std::cout << "Il tipo di dog è: " << dog.getType() << std::endl;
	dog.makeSound();

	std::cout << "---- Test polimorfismo con puntatori ----" << std::endl;
	AAnimal* animal1 = &cat;
	AAnimal* animal2 = &dog;

	std::cout << "Il tipo di animal1 (puntatore a cat) è: " << animal1->getType() << std::endl;
	animal1->makeSound();

	std::cout << "Il tipo di animal2 (puntatore a dog) è: " << animal2->getType() << std::endl;
	animal2->makeSound();

	return 0;
}

