/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:15:19 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/28 16:58:08 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str;
    std::string *stringPTR;
    std::string &stringREF = str;

    str = "HI THIS IS BRAIN";
    stringPTR = &str;

    std::cout << "The memory address of the string variable is:" << &str << std::endl;
    std::cout << "The memory address held by stringPTR is:" << stringPTR << std::endl;
    std::cout <<"The memory address held by stringREF is:" << &stringREF << std::endl;

    std::cout << "The value of the string variable is:" << str << std::endl;
    std::cout << "The value pointed to by stringPTR is:" << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is:" << stringREF << std::endl;
}