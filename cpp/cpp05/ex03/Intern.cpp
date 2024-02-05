/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:34:08 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 13:40:09 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &copy)
{
    if (this != &copy)
        *this = copy;
}

Intern Intern::operator=(const Intern &copy)
{
    if (this != &copy)
        return (*this);
    else
        return (*this);
}

Intern::~Intern()
{

}

AForm*    Intern::makeRRF(std::string FormName, std::string FormTarget)
{
    std::cout << "Intern creates " << FormName << std::endl;
    RobotomyRequestForm *ret_RRF = new RobotomyRequestForm;
    ret_RRF->set_name(FormName);
    ret_RRF->SetTarget(FormTarget);
    return (ret_RRF);
}

AForm*    Intern::makePPF(std::string FormName, std::string FormTarget)
{
    std::cout << "Intern creates " << FormName << std::endl;
    PresidentialPardonForm *ret_PPF = new PresidentialPardonForm;
    ret_PPF->set_name(FormName);
    ret_PPF->SetTarget(FormTarget);
    return (ret_PPF);
}

AForm*    Intern::makeSCF(std::string FormName, std::string FormTarget)
{
    std::cout << "Intern creates " << FormName << std::endl;
    ShrubberyCreationForm *ret_SCF = new ShrubberyCreationForm;
    ret_SCF->set_name(FormName);
    ret_SCF->SetTarget(FormTarget);
    return (ret_SCF);
}

AForm*  Intern::makeForm(std::string FormName, std::string FormTarget)
{
    std::string level_arr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    AForm* (Intern::*func[3])(std::string FormName, std::string FormTarget);

    func[0] = &Intern::makeRRF;
    func[1] = &Intern::makePPF;
    func[2] = &Intern::makeSCF;

    for (int i = 0; i < 3; i++)
    {
        if (level_arr[i] == FormName)
            return ((this->*func[i])(FormName, FormTarget));
    }
    std::cout << "Error" << std::endl;
    return (NULL);
}
