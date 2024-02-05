/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:03 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 15:01:56 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("b1", 1);
		PresidentialPardonForm p1("targetP");
		ShrubberyCreationForm s1("targetS");
		RobotomyRequestForm r1("targetR");

		s1.beSigned(b1);
		b1.signForm(s1);
		b1.executeForm(s1);
		std::cout << "\n";

		r1.beSigned(b1);
		b1.signForm(r1);
		b1.executeForm(r1);
		std::cout << "\n";

		p1.beSigned(b1);
		b1.signForm(p1);
		b1.executeForm(p1);
	}
	catch (std::exception & e)
	{
		std::cout << "exception" << std::endl;
	}
}