/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:52:42 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/28 16:08:05 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string name;
    Zombie      *tmp_zombie;

    name = "brain_eater";
    tmp_zombie = zombieHorde(10, name);
    for (int i = 0; i < 10; i++)
    {
        tmp_zombie[i].announce();
    }
    delete[] tmp_zombie;
}