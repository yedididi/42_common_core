/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:44:38 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/29 14:37:41 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon      *weapon;
        std::string name;
    public:
        HumanB(std::string tmp_name);
        void    attack(void);
        void    setWeapon(Weapon &tmp_weapon);
};

#endif