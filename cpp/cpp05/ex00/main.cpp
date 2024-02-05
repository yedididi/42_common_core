/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:03 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 15:25:55 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 2);
		Bureaucrat b3("b3", 3);
		Bureaucrat b4("b4", 4);

		std::cout << b1;
		std::cout << b2;
		std::cout << b3;
		std::cout << b4;

		b1.decrement();
		b2.decrement();
		b3.decrement();
		b4.decrement();

		std::cout << "\n";
		std::cout << b1;
		std::cout << b2;
		std::cout << b3;
		std::cout << b4;
	}
	catch (std::exception &e)
	{
		std::cout << "exception" << std::endl;
	}
}