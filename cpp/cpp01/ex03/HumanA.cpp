/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:43:03 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/29 14:35:38 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string tmp_name, Weapon &tmp_weapon)  : name(tmp_name), weapon(tmp_weapon)
{
    this->name = tmp_name;
    this->weapon = tmp_weapon;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}