/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:03 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 15:32:36 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("b1", 150);
		Form f1("f1", 0, 149, 149);

		std::cout << b1;
		std::cout << f1;
		std::cout << "\n";

		// f1.beSigned(b1);
		// b1.signForm(f1);
		// std::cout << "\n";

		b1.increment();

		std::cout << b1;
		std::cout << f1;
		std::cout << "\n";

		f1.beSigned(b1);
		b1.signForm(f1);
	}
	catch (std::exception & e)
	{
		std::cout << "exception" << std::endl;
	}
}