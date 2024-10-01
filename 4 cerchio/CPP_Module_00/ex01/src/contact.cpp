/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:27:05 by andrea            #+#    #+#             */
/*   Updated: 2024/08/27 19:44:42 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

void contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void contact::set_number(std::string number)
{
	this->number = number;
}

void contact::set_secret(std::string secret)
{
	this->secret = secret;
}

std::string contact::get_first_name()
{
	return (this->first_name);
}

std::string contact::get_last_name()
{
	return (this->last_name);
}

std::string contact::get_nickname()
{
	return (this->nickname);
}

std::string contact::get_number()
{
	return (this->number);
}

std::string contact::get_secret()
{
	return (this->secret);
}
