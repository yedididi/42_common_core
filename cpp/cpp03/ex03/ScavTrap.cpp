/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejilee <yejilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:29:45 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/13 14:33:57 by yejilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap's constructor called" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap's Copy constructor called" << std::endl;
    *this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout << "ScavTrap's Copy assignment operator called" << std::endl;
    this->name = obj.name;
    this->hit_points = obj.hit_points;
    this->energy_points = obj.energy_points;
    this->attack_damage = obj.attack_damage;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap's default destructor called" << std::endl;
}

void ScavTrap::attack(std::string const& target)
{
    if (this->energy_points > 0)
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points > 0)
    {
        std::cout << "ScavTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
        this->hit_points -= amount;
        if (this->hit_points < 0)
            this->hit_points = 0;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points > 0)
    {
        std::cout << "ScavTrap " << this->name << " is repaired " << amount << " points of HP!" << std::endl;
        this->hit_points += amount;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode." << std::endl;
}