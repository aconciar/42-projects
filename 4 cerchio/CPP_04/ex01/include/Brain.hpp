/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:37:05 by andrea            #+#    #+#             */
/*   Updated: 2024/10/16 16:54:05 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public :
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain& operator=(const Brain& other);

		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
	private :
		std::string ideas[100];
};

#endif