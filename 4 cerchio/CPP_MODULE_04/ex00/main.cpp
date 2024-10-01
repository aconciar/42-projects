/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:08:26 by andrea            #+#    #+#             */
/*   Updated: 2024/09/23 15:33:47 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Polimorfismo corretto con Animal, Dog e Cat
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();  // Uscita: "Meow! Meow!"
    j->makeSound();  // Uscita: "Woof! Woof!"
    meta->makeSound();  // Uscita: "Animal makes a sound..."

    delete (meta);
    delete (j);
    delete (i);

    // Polimorfismo errato con WrongAnimal e WrongCat
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound();  // Uscita: "WrongAnimal makes a weird sound..."
    wrongMeta->makeSound();  // Uscita: "WrongAnimal makes a weird sound..."

    delete (wrongMeta);
    delete (wrongCat);

    return (0);
}
