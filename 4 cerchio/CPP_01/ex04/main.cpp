/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:45:11 by andrea            #+#    #+#             */
/*   Updated: 2024/10/11 15:08:40 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static int	ft_open_file(std::ifstream &infile, std::ofstream &outfile, const std::string &filename)
{
	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error: Unable to open the input file" << std::endl;
		return (1);
	}
	outfile.open((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error: Unable to create or open the output file" << std::endl;
		return (1);
	}
	return (0);
}

static void	ft_replace(std::string &filename, std::string s1, std::string s2)
{
	size_t pos = 0;

	while ((pos = filename.find(s1, pos)) != std::string::npos)
	{
		filename.replace(pos, s1.length(), s2);
		pos += s2.length();
	}
}

int	main(int argc, char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::ifstream infile;
	std::ofstream outfile;

	if (argc != 4)
	{
		std::cout << "Invalid Argument" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return (1);
	}
	if (ft_open_file(infile, outfile, filename))
		return (1);
	while (std::getline(infile, filename))
	{
		ft_replace(filename, s1, s2);
		outfile << filename << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
