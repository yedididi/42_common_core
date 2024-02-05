/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:05:45 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/28 12:16:03 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "enter command:" << std::endl;
        std::cin >> command;
        if (command == "ADD" || command == "add")
            phonebook.add();
        else if (command == "SEARCH" || command == "search")
            phonebook.search();
        else if (command == "EXIT" || command == "exit")
            break ;
        else
            std::cout << "command not found" << std::endl;
    }
    return (0);
}