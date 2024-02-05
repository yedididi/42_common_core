/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:15:54 by yejlee2           #+#    #+#             */
/*   Updated: 2024/01/04 11:32:06 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    try 
    {
        if (argc != 2)
            throw std::out_of_range("wrong input\n");
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout << "exception" << std::endl;
    }
    
}