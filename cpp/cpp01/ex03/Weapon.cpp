/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:45:02 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/29 13:49:25 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    this->type = "";
}

Weapon::Weapon(std::string tmp_type)
{
    this->type = tmp_type;
}

const std::string&   Weapon::getType(void)
{
    std::string &ret_type = this->type;
    return (ret_type);
}    
       
void    Weapon::setType(std::string new_type)
{
    this->type = new_type;
}