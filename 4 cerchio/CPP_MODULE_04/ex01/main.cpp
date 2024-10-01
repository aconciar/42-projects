/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:08:26 by andrea            #+#    #+#             */
/*   Updated: 2024/09/23 15:58:31 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Creazione di un array di puntatori a oggetti Animal
    const int arraySize = 6;
    Animal* animals[arraySize];

    // Riempimento con Dog e Cat
    for (int i = 0; i < arraySize / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; ++i) {
        animals[i] = new Cat();
    }

    // Distruzione di tutti gli animali
    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];  // Deve chiamare il distruttore corretto
    }

    // Test per deep copy
    Dog originalDog;
    Dog copiedDog = originalDog;  // Deep copy

    Cat originalCat;
    Cat copiedCat = originalCat;  // Deep copy

    return (0);
}
