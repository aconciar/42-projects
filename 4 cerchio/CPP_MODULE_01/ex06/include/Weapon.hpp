/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:02:02 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 12:05:41 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string &getType() const;
        void setType(std::string type);

    private:
        std::string _type;
};

#endif