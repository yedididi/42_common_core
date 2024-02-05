/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:33:20 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 14:59:33 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : sign_grade(150), execute_grade(150)
{
    std::string &tmp = const_cast<std::string &>(this->name);
    tmp = "";
    this->is_signed = 0;
}

AForm::AForm(const std::string name, bool is_signed, const int sign_grade, const int execute_grade) : sign_grade(sign_grade), execute_grade(execute_grade)
{
    std::string &tmp = const_cast<std::string &>(this->name);
    tmp = name;
    this->is_signed = is_signed;
    if (sign_grade > 150 || execute_grade > 150)
        AForm::GradeTooLowException();
    else if (sign_grade < 1 || execute_grade < 1)
        AForm::GradeTooHighException();
}

AForm::AForm(const AForm &copy) : sign_grade(copy.sign_grade), execute_grade(copy.execute_grade)
{
    if (this != &copy)
    {
        std::string &tmp = const_cast<std::string &>(this->name);
        tmp = copy.name;
        this->is_signed = copy.is_signed;
    }
}

AForm& AForm::operator=(const AForm &copy)
{
    if (this != &copy)
    {
        std::string &tmp = const_cast<std::string &>(this->name);
        tmp = copy.name;
        int &sign = const_cast<int &>(this->sign_grade);
        sign = copy.sign_grade;
        int &execute = const_cast<int &>(this->execute_grade);
        execute = copy.execute_grade;
        this->is_signed = copy.is_signed;
    }
    return (*this);
}

AForm::~AForm(void)
{
}

std::string AForm::get_name(void) const
{
    return (this->name);
}

bool    AForm::get_is_signed(void) const
{
    return (this->is_signed);
}

int   AForm::get_sign_grade(void) const 
{
    return (this->sign_grade);
}

int   AForm::get_execute_grade(void) const 
{
    return (this->execute_grade);
}

void    AForm::beSigned(Bureaucrat &bur)
{
    if (bur.getgrade() <= this->sign_grade)
        this->is_signed = 1;
}

void    AForm::GradeTooLowException(void)
{
    std::cout << "Grade too low" << std::endl;
    throw std::exception();
}

void    AForm::GradeTooHighException(void)
{
    std::cout << "Grade too high" << std::endl;
    throw std::exception();
}

void    AForm::set_name(std::string name)
{
    std::string &tmp = const_cast<std::string &>(this->name);
    tmp = name;
}

void    AForm::set_is_signed(bool is_signed)
{
    this->is_signed = is_signed;
}

void    AForm::set_grade(int sign_grade, int execute_grade)
{
    int &sign = const_cast<int &>(this->sign_grade);
    sign = sign_grade;
    int &execute = const_cast<int &>(this->execute_grade);
    execute = execute_grade;
}
