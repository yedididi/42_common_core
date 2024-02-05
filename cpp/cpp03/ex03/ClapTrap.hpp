/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejilee <yejilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:32 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/13 14:00:54 by yejilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int         hit_points;
        int         energy_points;
        int         attack_damage;
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& obj);
        ClapTrap& operator=(const ClapTrap& rhs);
        ~ClapTrap();
        void attack(const std::string& target); 
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif