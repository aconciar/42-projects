/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:44:27 by aconciar          #+#    #+#             */
/*   Updated: 2025/04/22 18:45:28 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string.h>
#include <iostream>

class Warlock
{
	private:
		std::string	name:
		std::string	title;
		Warlock();
		Warlock(const Warlock &other);

	public:
		Warlock(const std::string &tmpName,const std::string &tmpTitle);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTile(const std::string &str);
		void setName(const std::string &str);

		void introduce() const;
};

#endif