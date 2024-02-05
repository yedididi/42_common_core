/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:06 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/26 15:28:44 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(void);
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat(void);
        Bureaucrat &operator=(const Bureaucrat &copy);
        std::string getname(void) const;
        int getgrade(void) const;
        void increment(void);
        void decrement(void);
        int GradeTooHighException(void);
        int GradeTooLowException(void);
        void    signForm(Form &f);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bur);

#endif