/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:23 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/14 15:03:44 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap player_A("A");
    ScavTrap player_B("B");

    player_A.attack("B");
    player_B.takeDamage(30);
    player_B.beRepaired(10);

    std::cout << "\n";

    player_B.attack("A");
    player_A.takeDamage(30);
    player_A.beRepaired(10);


    player_A.guardGate();
    player_B.guardGate();
}