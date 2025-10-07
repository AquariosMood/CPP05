/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:50:44 by crios             #+#    #+#             */
/*   Updated: 2025/08/30 10:39:26 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
// {
//     std::cout << "Bureaucrat default constructor called" << std::endl;
// }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "💼 Bureaucrat constructor called 💼" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "💼 Bureaucrat copy constructor called 💼" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "💼 Bureaucrat assignment operator called 💼" << std::endl;
    if (this != &other)
    {
        // _name = other._name; // _name is const, cannot be assigned
        _grade = other._grade;
    }
    return *this;
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "💼 Bureaucrat destructor called 💼" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
