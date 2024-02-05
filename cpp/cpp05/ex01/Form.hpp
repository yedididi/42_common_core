/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:04:54 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 15:21:26 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool    is_signed;
		const int	sign_grade;
		const int	execute_grade;
    public:
        Form(void);
        Form(std::string const name, bool is_signed, const int sign_grade, const int execute_grade);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form(void);
        std::string get_name(void) const;
        bool        get_is_signed(void) const;
        int   get_sign_grade(void) const;
        int   get_execute_grade(void) const;
        void        beSigned(Bureaucrat &bur);
        int        GradeTooLowException(void);
        int        GradeTooHighException(void);
};

std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif