/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:31 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/28 12:17:40 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void    print_index(std::string str)
{
    if (str.size() < 10)
    {
        for (int i = str.size(); i < 10; i++)
            std::cout << " ";
        std::cout << str;
        std::cout << "|";
    }
    else
        std::cout << str.substr(0, 9) << "." << "|";
}

void Contact::add(void)
{
    std::cout << "enter first name: " << std::endl;
    std::cin >> this->first_name;
    std::cout << "enter last name: " << std::endl;
    std::cin >> this->last_name;
    std::cout << "enter nickname: " << std::endl;
    std::cin >> this->nickname;
    std::cout << "enter phone number: " << std::endl;
    std::cin >> this->phone_number;
    std::cout << "enter darkest secret: " << std::endl;
    std::cin >> this->darkest_secret;
}

void    Contact::print_arr(int version)
{
    if (version == 0)
    {
        print_index(this->first_name);
        print_index(this->last_name);
        print_index(this->nickname);
        std::cout << std::endl;
    }
    else if (version == 1)
    {
        std::cout << "first name: " << this->first_name << std::endl;
        std::cout << "last_name: " <<  this->last_name << std::endl;
        std::cout << "nickname: " <<  this->nickname << std::endl;
        std::cout << "phone_number: " <<  this->phone_number << std::endl;
        std::cout << "darkest_secret: " <<  this->darkest_secret << std::endl;
    }
}