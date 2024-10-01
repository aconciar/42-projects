/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:55:43 by andrea            #+#    #+#             */
/*   Updated: 2024/09/30 18:24:29 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

#include <iostream>

class phonebook
{

	public:
		phonebook();
		~phonebook();
		void    add_contact();
		void    search_contact();
		void    print_contact(int index);

	private:
		contact	contacts[8];
		int     index;
		int		contact_count;
};

#endif