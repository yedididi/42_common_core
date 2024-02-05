/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:33:20 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 14:23:24 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : sign_grade(150), execute_grade(150)
{
    std::string &tmp = const_cast<std::string &>(this->name);
    tmp = "";
    this->is_signed = 0;
}

Form::Form(const std::string name, bool is_signed, const int sign_grade, const int execute_grade) : sign_grade(sign_grade), execute_grade(execute_grade)
{
    std::string &tmp = const_cast<std::string &>(this->name);
    tmp = name;
    this->is_signed = is_signed;
    if (sign_grade > 150 || execute_grade > 150)
        throw Form::GradeTooLowException();
    else if (sign_grade < 1 || execute_grade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &copy) : sign_grade(copy.sign_grade), execute_grade(copy.execute_grade)
{
    if (this != &copy)
    {
        std::string &tmp = const_cast<std::string &>(copy.name);
        tmp = copy.name;
        this->is_signed = copy.is_signed;
    }
}

Form& Form::operator=(const Form &copy)
{
    if (this != &copy)
    {
        std::string &tmp = const_cast<std::string &>(copy.name);
        tmp = copy.name;
        int &sign = const_cast<int &>(copy.sign_grade);
        sign = copy.sign_grade;
        int &execute = const_cast<int &>(copy.execute_grade);
        execute = copy.execute_grade;
        this->is_signed = copy.is_signed;
    }
    return (*this);
}

Form::~Form(void)
{
}

std::string Form::get_name(void) const
{
    return (this->name);
}

bool    Form::get_is_signed(void) const
{
    return (this->is_signed);
}

int   Form::get_sign_grade(void) const
{
    return (this->sign_grade);
}

int   Form::get_execute_grade(void) const
{
    return (this->execute_grade);
}

void    Form::beSigned(Bureaucrat &bur)
{
    if (bur.getgrade() <= this->sign_grade)
        this->is_signed = 1;
    else
        throw Form::GradeTooLowException();
}

int    Form::GradeTooLowException(void)
{
    std::cout << "Grade too low" << std::endl;
    throw std::exception();
}

int    Form::GradeTooHighException(void)
{
    std::cout << "Grade too high" << std::endl;
    throw std::exception();
}

std::ostream &operator<<(std::ostream &out, const Form &Form)
{
    out << "name :" << Form.get_name() << ", ";
    out << "is_signed :" << Form.get_is_signed() << ", ";
    out << "sign_grade :" << Form.get_sign_grade() << ", ";
    out << "execute_grade :" << Form.get_execute_grade() << std::endl;
    return (out);
}