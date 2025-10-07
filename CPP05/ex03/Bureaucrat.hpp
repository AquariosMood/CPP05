/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:05 by crios             #+#    #+#             */
/*   Updated: 2025/08/28 13:28:05 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const   _name ;
        int                 _grade;
    public:
    //    Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string const &getName() const;
        int getGrade() const;

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

        void incrementGrade()
        {
            if (_grade <= 1)
                throw GradeTooHighException();
            _grade--;
        }
        void decrementGrade()
        {
            if (_grade >= 150)
                throw GradeTooLowException();
            _grade++;
        }
    
        void signForm(AForm &form);
        void executeForm(AForm &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif