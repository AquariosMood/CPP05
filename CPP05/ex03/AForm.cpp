/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:32:36 by crios             #+#    #+#             */
/*   Updated: 2025/08/28 12:07:56 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "📝 Form constructor called 📝" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "📝 Form copy constructor called 📝" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "📝 Form assignment operator called 📝" << std::endl;
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

std::string const &AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    int bureaucratGrade = bureaucrat.getGrade();
    if (bureaucratGrade < 1)
    {
        std::cout << "🚨 Bureaucrat " << bureaucrat.getName() << " has a grade too high! 🚨" << std::endl;
        throw GradeTooHighException();
    }
    else if (bureaucratGrade > 150)
    {
        std::cout << "🚨 Bureaucrat " << bureaucrat.getName() << " has a grade too low! 🚨" << std::endl;
        throw GradeTooLowException();
    }
    if (bureaucratGrade > gradeToSign)
    {
        std::cout << "🚨 Bureaucrat " << bureaucrat.getName() << " cannot sign the form! 🚨" << std::endl;
        throw GradeTooLowException();
    }
    std::cout << "📝 Bureaucrat " << bureaucrat.getName() << " signed the form! 📝" << std::endl;
    isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form Name: " << form.getName() << std::endl;
    os << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
    os << "Grade to Sign: " << form.getGradeToSign() << std::endl;
    os << "Grade to Execute: " << form.getGradeToExecute() << std::endl;
    return os;
}

AForm::~AForm()
{
    std::cout << "📝 Form destructor called 📝" << std::endl;
}