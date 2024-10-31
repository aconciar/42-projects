/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:35:51 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/01 15:45:24 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Complaining at DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nComplaining at INFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nComplaining at WARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nComplaining at ERROR level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nComplaining at INVALID level:" << std::endl;
    harl.complain("INVALID");

    return 0;
}
