/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:01:41 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 12:34:15 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Quando è appropriato aggiungere un distruttore esplicito?

// Aggiungere un distruttore esplicito ha senso quando:

//     Gestisci risorse manualmente: Se la classe alloca memoria dinamica (con new, malloc, o altre risorse come file, socket, ecc.), devi liberarle manualmente nel distruttore.

//     Logging o debugging: Se vuoi tracciare quando un oggetto viene distrutto, puoi aggiungere un distruttore esplicito per stampare messaggi di log.

//     Ereditarietà: Quando lavori con classi base e derivate, e vuoi assicurarti che i distruttori siano chiamati correttamente, specialmente quando utilizzi il polimorfismo.

#include "include/HumanA.hpp"
#include "include/HumanB.hpp"
#include "include/Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}