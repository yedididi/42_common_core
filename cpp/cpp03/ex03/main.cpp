/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:23 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/14 13:05:04 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap player_A("A");
    DiamondTrap player_B("B");

    std::cout << "\n";

    player_A.attack("B");
    player_B.takeDamage(20);
    player_B.beRepaired(10);

    std::cout << "\n";

    player_B.attack("A");
    player_A.takeDamage(20);
    player_A.beRepaired(10);

    std::cout << "\n";

    player_A.whoAmI();
    player_B.whoAmI();

    std::cout << "\n";
}