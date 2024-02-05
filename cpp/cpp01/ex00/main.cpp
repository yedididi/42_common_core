/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:21:18 by yejlee2           #+#    #+#             */
/*   Updated: 2023/10/05 11:38:16 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string name;
    Zombie      *tmp_zombie;

    name = "freshZombie";
    tmp_zombie = newZombie(name);
    tmp_zombie->announce();
    delete tmp_zombie;

    name = "randomZombie";
    randomChump(name);
}