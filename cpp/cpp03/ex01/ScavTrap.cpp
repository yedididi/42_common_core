/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:29:45 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/14 14:56:26 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :ClapTrap()
{
    std::cout << "ScavTrap's default constructor called" << std::endl;
    this->name = "default";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

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
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode." << std::endl;
}