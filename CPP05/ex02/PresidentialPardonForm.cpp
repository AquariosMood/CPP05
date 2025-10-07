/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:49:32 by crios             #+#    #+#             */
/*   Updated: 2025/07/12 15:40:11 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
// {
//     std::cout << "📝 Presidential Pardon Form default constructor called 📝" << std::endl;
// }

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << "📝 Presidential Pardon Form parameterized constructor called 📝" << std::endl;
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    std::cout << "📝 Presidential Pardon Form copy constructor called 📝" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "📝 Presidential Pardon Form assignment operator called 📝" << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

void PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat)
{
    std::cout << "Form grade to sign: " << getGradeToSign() << std::endl;
    std::cout << "Bureaucrat grade: " << bureaucrat.getGrade() << std::endl;

    if (bureaucrat.getGrade() > getGradeToSign())
        throw AForm::GradeTooLowException();
    isSigned = true;
    std::cout << "📝 Presidential Pardon Form signed successfully! 📝" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat &executor) const
{
    std::cout << "Form grade to execute: " << getGradeToExecute() << std::endl;
    std::cout << "Bureaucrat grade: " << executor.getGrade() << std::endl;

    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
    {
        std::cout << "🚨 Bureaucrat " << executor.getName() << " cannot execute the form! 🚨\n" << std::endl;
        throw AForm::GradeTooLowException();
    }

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n" << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "📝 Presidential Pardon Form destructor called 📝" << std::endl;
}
