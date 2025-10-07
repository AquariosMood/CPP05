/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:44:06 by crios             #+#    #+#             */
/*   Updated: 2025/07/12 15:44:17 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
// {
//     std::cout << "🤖 Robotomy Request Form default constructor called 🤖" << std::endl;
// }

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45)
{
    std::cout << "🤖 Robotomy Request Form parameterized constructor called 🤖" << std::endl;
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    std::cout << "🤖 Robotomy Request Form copy constructor called 🤖" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "🤖 Robotomy Request Form assignment operator called 🤖" << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat)
{
    std::cout << "Form grade to sign: " << getGradeToSign() << std::endl;
    std::cout << "Bureaucrat grade: " << bureaucrat.getGrade() << std::endl;

    if (bureaucrat.getGrade() > getGradeToSign())
        throw AForm::GradeTooLowException();
    isSigned = true;
    std::cout << "🤖 Robotomy Request Form signed successfully! 🤖" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const
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
    
    std::cout << "🤖 Robotomy Request Form executed successfully! 🤖\n" << std::endl;
    std::cout << "🔊 Bzzzzzz... Bzzzzzz... Bzzzzzz... 🔊" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << "🔊 " << this->getTarget() << " has been robotomized! 🔊\n" << std::endl;
    else
        std::cout << "❌ Robotomy failed for " << this->getTarget() << "! ❌\n" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "🤖 Robotomy Request Form destructor called 🤖" << std::endl;
}
