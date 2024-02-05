/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:03 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 15:11:59 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern someRandomIntern;
		AForm	*rrf;
		AForm	*ppf;
		AForm	*scf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		delete rrf;
		delete ppf;
		delete scf;	
	}
	catch (std::exception & e)
	{
		std::cout << "exception" << std::endl;
	}
}