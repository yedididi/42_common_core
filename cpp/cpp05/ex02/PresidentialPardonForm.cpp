/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:24:38 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 14:56:22 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    this->set_grade(25, 5);
    this->set_is_signed(0);
    this->set_name("PresidentialPardonForm");
    this->target = "";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    this->set_grade(25, 5);
    this->set_is_signed(0);
    this->set_name("PresidentialPardonForm");
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
    if (this != &copy)
    {
        this->target = copy.target;
        this->set_grade(copy.get_sign_grade(), copy.get_execute_grade());
        this->set_is_signed(copy.get_is_signed());
        this->set_name(copy.get_name());
    }
}

PresidentialPardonForm PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this != &copy)
    {
        this->target = copy.target;
        this->set_grade(copy.get_sign_grade(), copy.get_execute_grade());
        this->set_is_signed(copy.get_is_signed());
        this->set_name(copy.get_name());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getgrade() > this->get_execute_grade())
        throw PresidentialPardonForm::NonExecutable();
    if (this->get_is_signed() == 0)
        throw PresidentialPardonForm::NotSigned();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

int PresidentialPardonForm::NonExecutable() const
{
    std::cout << "bureaucrat's grade is not high enough to execute this form" << std::endl;
	throw std::exception();
}

int PresidentialPardonForm::NotSigned() const
{
    std::cout << "this form is not signed, thus cannot be executed" << std::endl;
	throw std::exception();
}