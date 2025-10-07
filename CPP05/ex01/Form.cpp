/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:11:21 by crios             #+#    #+#             */
/*   Updated: 2025/08/30 10:50:05 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "📝 Form constructor called 📝" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "📝 Form copy constructor called 📝" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "📝 Form assignment operator called 📝" << std::endl;
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

std::string const &Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form Name: " << form.getName() << std::endl;
    os << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
    os << "Grade to Sign: " << form.getGradeToSign() << std::endl;
    os << "Grade to Execute: " << form.getGradeToExecute() << std::endl;
    return os;
}

Form::~Form()
{
    std::cout << "📝 Form destructor called 📝" << std::endl;
}