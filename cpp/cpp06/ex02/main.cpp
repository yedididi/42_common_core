/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:47:40 by yejlee2           #+#    #+#             */
/*   Updated: 2024/01/05 10:51:13 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <fstream>

Base* generate(void)
{
    char    c;
    std::ifstream readfile;
    Base *ret_class;

    readfile.open("/dev/random");
    readfile.get(c);
    if (c % 3 == 0)
        ret_class = new A;
    else if (c % 3 == 1)
        ret_class = new B;
    else
        ret_class = new C;
    return (ret_class);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "pointer: A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "pointer: B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "pointer: C\n";
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "reference:A" << std::endl;
        (void)a;
        
    }
    catch (std::exception &e) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "reference:B" << std::endl;
        (void)b;
    }
    catch (std::exception &e) {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "reference:C" << std::endl;
        (void)c;
    }
    catch (std::exception &e) {}
}

int main(void)
{
    Base *base;

    base = generate();
    identify(base);
    identify(*base);
    delete base;
    return (0);
}