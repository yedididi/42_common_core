/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:23 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/14 13:10:55 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap player_A("A");
    ClapTrap player_B("B");

    player_A.attack("B");
    player_B.takeDamage(0);
    player_B.beRepaired(10);

    player_B.attack("A");
    player_A.takeDamage(0);
    player_A.beRepaired(10);
}