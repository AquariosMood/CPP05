/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:42 by crios             #+#    #+#             */
/*   Updated: 2025/07/12 15:41:02 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
    std::srand(std::time(0));   

    // Test ShrubberyCreationForm
    try
    {
        std::cout << "\n===== SHRUBBERY CREATION FORM =====" << std::endl;
        Bureaucrat bob("Spongebob", 130);
        ShrubberyCreationForm krusty("Krusty Krab");
        std::cout << "\n===== TEST 1: Sign the form =====" << std::endl;
        krusty.beSigned(bob);
        std::cout << "\n===== TEST 2: Execute the form =====" << std::endl;
        krusty.execute(bob);        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test RobotomyRequestForm
    try
    {
        std::cout << "\n===== ROBOTOMY REQUEST FORM =====" << std::endl;
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robo("Bender");
        std::cout << "\n===== TEST 3: Sign and execute robotomy =====" << std::endl;
        robo.beSigned(alice);
        robo.execute(alice);
        std::cout << "\n===== TEST 4: Try again (different result) =====" << std::endl;
        robo.execute(alice);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test PresidentialPardonForm
    try
    {
        std::cout << "\n===== PRESIDENTIAL PARDON FORM =====" << std::endl;
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Criminal");
        std::cout << "\n===== TEST 5: Sign and execute pardon =====" << std::endl;
        pardon.beSigned(president);
        pardon.execute(president);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test grade too low for signing
    try
    {
        std::cout << "\n===== TEST 6: Grade too low for signing =====" << std::endl;
        Bureaucrat lowGrade("LowGrade", 150);
        ShrubberyCreationForm shrub("garden");
        lowGrade.signForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test grade too low for execution
    try
    {
        std::cout << "\n===== TEST 7: Grade too low for execution =====" << std::endl;
        Bureaucrat signer("Signer", 140);
        Bureaucrat lowExecutor("LowExecutor", 150);
        RobotomyRequestForm robo2("Target");
        signer.signForm(robo2);
        lowExecutor.executeForm(robo2);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test executing unsigned form
    try
    {
        std::cout << "\n===== TEST 8: Execute unsigned form =====" << std::endl;
        Bureaucrat executor("Executor", 1);
        PresidentialPardonForm unsigned_form("Target");
        executor.executeForm(unsigned_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}