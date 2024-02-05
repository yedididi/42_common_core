/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:40:10 by yejilee           #+#    #+#             */
/*   Updated: 2023/11/14 13:04:58 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap's constructor called" << std::endl;
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "DiamondTrap's copy constructor called" << std::endl;
    *this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
    std::cout << "DiamondTrap's Copy assignment operator called" << std::endl;
    this->name = copy.name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap's default destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My ClapTrap name is:" << ClapTrap::name << std::endl;
    std::cout << "My DiamondTrap name is:" << DiamondTrap::name << std::endl;
}