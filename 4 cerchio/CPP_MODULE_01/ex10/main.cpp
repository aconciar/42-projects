/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:55:52 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 15:17:09 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static void ft_printfile(std::string filename)
{
    std::string line;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file" << std::endl;
        return ;
    }
    while (std::getline(file, line))
        std::cout << line << std::endl;
    file.close(); 
}

void ft_read_stdin()
{
    std::string line;
    while (std::getline(std::cin, line))
        std::cout << line << std::endl;
}

int main(int argc, char **argv)
{
    int i = 1;
    if (argc == 1)
    {
        ft_read_stdin();
        return (0);
    }
    while (i < argc)
    {
        std::string filename = argv[i];
        if (filename == "-")
            ft_read_stdin();
        else
            ft_printfile(filename);
        i++;
    }
    return (0);
}
