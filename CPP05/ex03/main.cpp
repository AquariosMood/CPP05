/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:42 by crios             #+#    #+#             */
/*   Updated: 2025/05/22 12:15:12 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form = NULL;

    try {
        std::cout << "\n===============" << std::endl;
        // Test 1: Valid form creation and execution
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat bob("Spongebob", 45);
        std::cout << "===== Test 1: Robotomy Request =====" << std::endl;
        std::cout << bob << std::endl;
        std::cout << *form << std::endl;
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    } catch (const std::exception& e) {
        std::cerr << "Exception in Test 1: " << e.what() << std::endl;
        delete form;
    }

    try {
        std::cout << "\n===============" << std::endl;
        // Test 2: Unknown form type
        std::cout << "\n===== Test 2: Unknown Form =====" << std::endl;
        form = someRandomIntern.makeForm("unknown form", "Target");
        if (form)
            delete form;
    } catch (const std::exception& e) {
        std::cerr << "Exception in Test 2: " << e.what() << std::endl;
        delete form;
    }

    try {
        std::cout << "\n===============" << std::endl;
        // Test 3: Bureaucrat with low grade tries to sign
        form = someRandomIntern.makeForm("presidential pardon", "Rick");
        Bureaucrat lowRank("Patrick", 150);
        std::cout << "\n===== Test 3: Low Grade Bureaucrat =====" << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << *form << std::endl;
        lowRank.signForm(*form);
        lowRank.executeForm(*form);
        delete form;
    } catch (const std::exception& e) {
        std::cerr << "Exception in Test 3: " << e.what() << std::endl;
        delete form;
    }

    try {
        std::cout << "\n===============" << std::endl;
        // Test 4: Bureaucrat executes unsigned form
        form = someRandomIntern.makeForm("shrubbery creation", "Garden");
        Bureaucrat midRank("Squidward", 100);
        std::cout << "\n===== Test 4: Execute Unsigned Form =====" << std::endl;
        std::cout << midRank << std::endl;
        std::cout << *form << std::endl;
        midRank.executeForm(*form);
        delete form;
    } catch (const std::exception& e) {
        std::cerr << "Exception in Test 4: " << e.what() << std::endl;
        delete form;
    }

    return 0;
}
