/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:30:28 by crios             #+#    #+#             */
/*   Updated: 2025/08/28 13:28:05 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        std::string const   _name;
        bool                isSigned;
        int const           gradeToSign;
        int const           gradeToExecute;

    public:
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

        virtual ~AForm();
        
        std::string const &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
    
        virtual void beSigned(Bureaucrat &bureaucrat);
        
        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return "📈 Grade too high!";
            }
        };
        class GradeTooLowException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return "📉 Grade too low!";
            }
        };
        
        virtual void execute(Bureaucrat &executor) const = 0;
    };

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif