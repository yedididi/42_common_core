/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:25:42 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 13:27:29 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    this->set_grade(72, 45);
    this->set_is_signed(0);
    this->set_name("R");
    this->target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
    this->set_grade(72, 45);
    this->set_is_signed(0);
    this->set_name("R");
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        this->set_grade(copy.get_sign_grade(), copy.get_execute_grade());
        this->set_is_signed(copy.get_is_signed());
        this->set_name(copy.get_name());
        this->target = copy.target;
    }
}

RobotomyRequestForm RobotomyRequestForm::operator=(const RobotomyRequestForm & copy)
{
    if (this != &copy)
    {
        this->set_grade(copy.get_sign_grade(), copy.get_execute_grade());
        this->set_is_signed(copy.get_is_signed());
        this->set_name(copy.get_name());
        this->target = copy.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    char    c;
    std::ifstream readfile;

    if (executor.getgrade() > this->get_execute_grade())
        throw RobotomyRequestForm::NonExecutable();
    if (this->get_is_signed() == 0)
        throw RobotomyRequestForm::NotSigned();
    std::cout << "***LOUD DRILLING NOISES***" << std::endl;
    readfile.open("/dev/random");
    readfile.get(c);
    if (c % 2 == 0)
        std::cout << this->target << " has been successfully robotomized" << std::endl;
    else
        std::cout << this->target << "'s robotomy has failed" << std::endl;
}

int RobotomyRequestForm::NonExecutable() const
{
    std::cout << "bureaucrat's grade is not high enough to execute this form" << std::endl;
	throw std::exception();
}

int RobotomyRequestForm::NotSigned() const
{
    std::cout << "this form is not signed, thus cannot be executed" << std::endl;
	throw std::exception();
}

void    RobotomyRequestForm::SetTarget(std::string target)
{
    this->target = target;
}