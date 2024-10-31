/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:08:26 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:53:58 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Cat.hpp"
#include "include/Dog.hpp"

int main()
{
	std::cout << "---- Creazione di cat1 ----" << std::endl;
	Cat cat1;
	cat1.setBrainIdea(0, "Eat fish");
	cat1.setBrainIdea(1, "Sleep on the couch");

	std::cout << "\n---- Creazione di cat2 (copia di cat1) ----" << std::endl;
	Cat cat2(cat1);

	std::cout << "\n---- Verifica che cat2 abbia le stesse ideas di cat1 ----" << std::endl;
	std::cout << "cat1 idea 0: " << cat1.getBrainIdea(0) << std::endl;
	std::cout << "cat2 idea 0: " << cat2.getBrainIdea(0) << std::endl;

	std::cout << "cat1 idea 1: " << cat1.getBrainIdea(1) << std::endl;
	std::cout << "cat2 idea 1: " << cat2.getBrainIdea(1) << std::endl;

	std::cout << "\n---- Modifica idea di cat2 e verifica che cat1 non cambi ----" << std::endl;
	cat2.setBrainIdea(0, "Chase birds");

	std::cout << "cat1 idea 0: " << cat1.getBrainIdea(0) << std::endl;
	std::cout << "cat2 idea 0: " << cat2.getBrainIdea(0) << std::endl;

	std::cout << "\n---- Assegnazione di cat3 = cat1 ----" << std::endl;
	Cat cat3;
	cat3 = cat1;

	std::cout << "\n---- Verifica che cat3 abbia le stesse ideas di cat1 ----" << std::endl;
	std::cout << "cat1 idea 0: " << cat1.getBrainIdea(0) << std::endl;
	std::cout << "cat3 idea 0: " << cat3.getBrainIdea(0) << std::endl;

	std::cout << "cat1 idea 1: " << cat1.getBrainIdea(1) << std::endl;
	std::cout << "cat3 idea 1: " << cat3.getBrainIdea(1) << std::endl;

	std::cout << "\n---- Fine del main, distruzione degli oggetti ----" << std::endl;

	return 0;
}

