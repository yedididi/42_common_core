/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:26:35 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 13:27:26 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    this->set_grade(145, 137);
    this->set_is_signed(0);
    this->set_name("S");
    this->target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    this->set_grade(145, 137);
    this->set_is_signed(0);
    this->set_name("S");
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        this->set_grade(copy.get_sign_grade(), copy.get_execute_grade());
        this->set_is_signed(copy.get_is_signed());
        this->set_name(copy.get_name());
        this->target = copy.target;
    }
}

ShrubberyCreationForm ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
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

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::ofstream   writefile;
    std::string file_name;

    if (executor.getgrade() > this->get_execute_grade())
        throw ShrubberyCreationForm::NonExecutable();
    if (this->get_is_signed() == 0)
        throw ShrubberyCreationForm::NotSigned();
    file_name = this->target;
    file_name = file_name.append("_shrubbery");
    writefile.open(file_name);
    writefile << "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____" << std::endl;
}

int ShrubberyCreationForm::NonExecutable() const
{
    std::cout << "bureaucrat's grade is not high enough to execute this form" << std::endl;
	throw std::exception();
}

int ShrubberyCreationForm::NotSigned() const
{
    std::cout << "this form is not signed, thus cannot be executed" << std::endl;
	throw std::exception();
}

void    ShrubberyCreationForm::SetTarget(std::string target)
{
    this->target = target;
}