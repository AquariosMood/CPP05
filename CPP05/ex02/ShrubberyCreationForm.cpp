/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:38:52 by crios             #+#    #+#             */
/*   Updated: 2025/08/28 12:07:56 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
// {
//     std::cout << "🌳 Shrubbery Creation Form default constructor called 🌳" << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
    std::cout << "🌳 Shrubbery Creation Form parameterized constructor called 🌳" << std::endl;
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "🌳 Shrubbery Creation Form copy constructor called 🌳" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "🌳 Shrubbery Creation Form assignment operator called 🌳" << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const
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

    std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Failed to open file for shrubbery creation." << std::endl;
        return;
    }
    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;
    ofs.close();
}

void ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat)
{
    int bureaucratGrade = bureaucrat.getGrade();
    std ::cout << "📝 Bureaucrat " << bureaucrat.getName() << " is trying to sign the form! 📝" << std::endl;
    std::cout << "📝 Bureaucrat grade: " << bureaucratGrade << " 📝" << std::endl;
    std::cout << "📝 Form grade to sign: " << getGradeToSign() << " 📝" << std::endl;
    if (bureaucratGrade < 1)
    {
        std::cout << "🚨 Bureaucrat " << bureaucrat.getName() << " has a grade too high! 🚨" << std::endl;
        throw GradeTooHighException();
    }
    else if (bureaucratGrade > getGradeToSign())
    {
        std::cout << "🚨 Bureaucrat " << bureaucrat.getName() << " has a grade too low! 🚨" << std::endl;
        throw GradeTooLowException();
    }
    std::cout << "📝 Bureaucrat " << bureaucrat.getName() << " signed the form! 📝" << std::endl;
    isSigned = true;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "🌳 Shrubbery Creation Form destructor called 🌳" << std::endl;
}
