/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:22:05 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 14:24:15 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main() {
    Human human;

    human.action("melee", "Goblin");
    human.action("ranged", "Dragon");
    human.action("shout", "Bandit");
    human.action("run", "Orc");

    return 0;
}
