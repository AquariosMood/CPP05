/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:57:50 by crios             #+#    #+#             */
/*   Updated: 2025/08/28 12:07:56 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "👨‍🎓 Intern default constructor called 👨‍🎓" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "👨‍🎓 Intern copy constructor called 👨‍🎓" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "👨‍🎓 Intern assignment operator called 👨‍🎓" << std::endl;
    if (this != &other)
    {
    }
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm* form = NULL;
    if (name == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else if (name == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (name == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else
    {
        std::cout << "Intern couldn't find the form: " << name << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << name << std::endl;
    return form;
}

Intern::~Intern()
{
    std::cout << "👨‍🎓 Intern destructor called 👨‍🎓" << std::endl;
}
