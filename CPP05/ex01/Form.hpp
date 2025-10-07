/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:11:12 by crios             #+#    #+#             */
/*   Updated: 2025/08/28 13:28:05 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

# include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                isSigned;
        int const           gradeToSign;
        int const           gradeToExecute;
    public:
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);

        ~Form();
        
        std::string const &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat &bureaucrat);
        
        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return "📈 Grade too high! Maximum grade is 1 📈";
            }
        };
        class GradeTooLowException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return "📉 Grade too low! Minimum grade is 150 📉";
            }
        };
    };

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif