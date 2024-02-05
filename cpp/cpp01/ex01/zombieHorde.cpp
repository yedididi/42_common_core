/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:52:52 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/28 15:58:55 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name)
{
    Zombie  *zombie = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        zombie[i].name_zombie(name);
    }
    return (zombie);
}