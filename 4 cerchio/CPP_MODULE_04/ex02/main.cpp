/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:08:26 by andrea            #+#    #+#             */
/*   Updated: 2024/09/23 16:05:53 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Non è più possibile istanziare direttamente Animal poiché è astratto
    // const Animal* meta = new Animal();  // Questo genererebbe un errore

    // Creiamo un Dog e un Cat attraverso puntatori di tipo Animal
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();  // Uscita: "Meow! Meow!"
    j->makeSound();  // Uscita: "Woof! Woof!"

    // Distruzione degli oggetti
    delete j;
    delete i;

    return (0);
}
