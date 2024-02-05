/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:04:54 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/22 17:24:57 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string	name;
        bool				is_signed;
		const int			sign_grade;
		const int			execute_grade;
    public:
        AForm(void);
        AForm(std::string const name, bool is_signed, const int sign_grade, const int execute_grade);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm(void);
        virtual std::string get_name(void) const;
        virtual bool        get_is_signed(void) const;
        virtual int			get_sign_grade(void) const;
        virtual int			get_execute_grade(void) const;
        virtual void        beSigned(Bureaucrat &bur);
        virtual void        GradeTooLowException(void);
        virtual void        GradeTooHighException(void);
        virtual void        set_name(std::string name);
        virtual void        set_is_signed(bool is_signed);
        virtual void        set_grade(int sign_grade, int execute_grade);
        virtual void        execute(Bureaucrat const &executor) const = 0;
};

#endif