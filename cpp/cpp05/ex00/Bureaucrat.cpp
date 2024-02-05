/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:08 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 15:24:27 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::string &tmp = const_cast<std::string &>(this->name);
    tmp = "";
	this->grade = 150;
}
        
Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	std::string &tmp = const_cast<std::string &>(this->name);
    tmp = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		std::string &tmp = const_cast<std::string &>(this->name);
		tmp = copy.name;
		this->grade = copy.grade;
	}
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		std::string &tmp = const_cast<std::string &>(this->name);
		tmp = copy.name;
		this->grade = copy.grade;
	}
	return (*this);
}

std::string Bureaucrat::getname() const
{
	return (this->name);
}

int Bureaucrat::getgrade() const
{
	return (this->grade);
}

void Bureaucrat::increment()
{
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

int Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade Too High" << std::endl;
	throw std::exception();
}

int Bureaucrat::GradeTooLowException()
{
	std::cout << "Grade Too Low" << std::endl;
	throw std::exception();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bur)
{
	out << Bur.getname() << ", bureaucrat grade " << Bur.getgrade() << "." << std::endl;
    return (out);
}