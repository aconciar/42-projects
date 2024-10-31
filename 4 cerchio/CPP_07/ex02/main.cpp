#include <iostream>
#include "Array.hpp"
#include "Array.hpp"
#include <iostream>

int main() {
    try{
        Array<int> emptyArray;
        std::cout << "Dimensione array vuoto: " << emptyArray.size() << std::endl;

        Array<int> intArray(5);
        std::cout << "Dimensione array int: " << intArray.size() << std::endl;

        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        Array<int> copyArray = intArray;
        std::cout << "Dimensione array copiato: " << copyArray.size() << std::endl;

        copyArray[0] = 999;
        std::cout << "Array originale, primo elemento: " << intArray[0] << std::endl;
        std::cout << "Array copiato, primo elemento: " << copyArray[0] << std::endl;

        std::cout << "Tentativo di accesso fuori dai limiti: " << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
