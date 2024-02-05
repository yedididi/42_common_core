/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:38 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/14 14:57:54 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap's default constructor called" << std::endl;
    this->name = "default";
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap's constructor called" << std::endl;
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "ClapTrap's Copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "ClapTrap's Copy assignment operator called" << std::endl;
    this->name = rhs.name;
    this->hit_points = rhs.hit_points;
    this->energy_points = rhs.energy_points;
    this->attack_damage = rhs.attack_damage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap's default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target <<", causing " << this->attack_damage<< " points of damage!" << std::endl;
        this->energy_points--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " is attacked, and lost " << amount << " points of hit point" << std::endl;
    this->hit_points = this->hit_points - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " is repaired, and gained " << amount << " points of hit point" << std::endl;
        this->hit_points = this->hit_points + amount;
        this->energy_points--;
    }
}