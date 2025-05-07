/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:46:21 by aconciar          #+#    #+#             */
/*   Updated: 2024/10/10 18:09:23 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data originalData;
	originalData.n = 42;
	originalData.str = "Data string";

	unsigned long raw = Serializer::serialize(&originalData);
	std::cout << "Serialized address: " << raw << std::endl;
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << deserializedData << std::endl;

	if (deserializedData == &originalData)
	{
		std::cout << "Serialization and deserialization successful!" << std::endl;
	}
	else
	{
		std::cout << "Error: Serialization and deserialization failed." << std::endl;
	}

	std::cout << "Data n: " << deserializedData->n << std::endl;
	std::cout << "Data str: " << deserializedData->str << std::endl;
	return (0);
}
