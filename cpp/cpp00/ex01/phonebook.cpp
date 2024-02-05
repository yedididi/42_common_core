/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:43:05 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/28 12:15:45 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{ 
    i = 0;
    oldest_index = 0;
}

void PhoneBook::add(void)
{
    this->contact_arr[this->oldest_index].add();
    this->i++;
    this->oldest_index = this->i % 8;
}

void PhoneBook::search(void)
{
    int i;

    i = 0;
    if (this->i == 0)
    {
        std::cout << "nothing added to the phonebook" << std::endl;
        return ;
    }
    std::cout << "     index| firstname|  lastname|  nickname|" << std::endl; 
    while (8 > i)
    {
        std::cout << "         " << i << "|";
        contact_arr[i].print_arr(0);
        i++;
    }
    std::cout << "enter index: " << std::endl;
    std::cin >> i;
    if (std::cin.fail())
    {
        std::cout << "wrong index type" << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    else if ((i < 0 || i > 7) || i + 1 > this->i)
        std::cout << "index is out of range" << std::endl;
    else
        contact_arr[i].print_arr(1);
}