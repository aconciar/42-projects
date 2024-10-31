/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:22:22 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 14:24:35 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
    std::cout << "Melee attack on " << target << "! They didn't see that coming!" << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
    std::cout << "Ranged attack on " << target << "! Precision shot, bullseye!" << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
    std::cout << target << " trembles in fear from the terrifying shout! What a coward!" << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
    int i = 0;

    std::string actions[] = {"melee", "ranged", "shout"};

    void (Human::*actionsFunctions[])(std::string const & target) =
        {
            &Human::meleeAttack,
            &Human::rangedAttack,
            &Human::intimidatingShout
        };

    while (i < 3)
    {
        if (action_name == actions[i])
        {
            (this->*actionsFunctions[i])(target);
            return;
        }
        i++;
    }
    std::cout << "Unknown action name: " << action_name << std::endl;
}
