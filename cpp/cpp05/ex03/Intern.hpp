/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:33:48 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 13:21:06 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &copy);
        Intern operator=(const Intern &copy);
        ~Intern();
        AForm   *makeForm(std::string FormName, std::string FormTarget);
        AForm*    makeRRF(std::string FormName, std::string FormTarget);
        AForm*    makePPF(std::string FormName, std::string FormTarget);
        AForm*    makeSCF(std::string FormName, std::string FormTarget);
};

#endif