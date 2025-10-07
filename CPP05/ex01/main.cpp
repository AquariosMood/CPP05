/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:42 by crios             #+#    #+#             */
/*   Updated: 2025/05/19 12:16:58 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "===== TEST 1: Form Creation and Basic Info =====" << std::endl;
    try 
    {
        Form form("Tax Form", 3, 5);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Invalid Form Creation (Grade too high) =====" << std::endl;
    try 
    {
        Form form("Invalid Form", 0, 5);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Invalid Form Creation (Grade too low) =====" << std::endl;
    try 
    {
        Form form("Invalid Form", 3, 151);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Successful Form Signing =====" << std::endl;
    try 
    {
        Form form("Application", 3, 5);
        Bureaucrat bob("Bob", 2);
        
        std::cout << form << std::endl;
        std::cout << bob << std::endl;
        
        bob.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: Failed Form Signing (Grade too low) =====" << std::endl;
    try 
    {
        Form form("Contract", 3, 5);
        Bureaucrat lowRank("LowRank", 4);
        
        std::cout << form << std::endl;
        std::cout << lowRank << std::endl;
        
        lowRank.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 6: Double Signing Attempt =====" << std::endl;
    try 
    {
        Form form("Agreement", 3, 5);
        Bureaucrat boss("Boss", 1);
        
        std::cout << form << std::endl;
        boss.signForm(form);
        std::cout << form << std::endl;
        
        // Try to sign again
        boss.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 7: Direct beSigned() Call =====" << std::endl;
    try 
    {
        Form form("Direct Form", 3, 5);
        Bureaucrat clerk("Clerk", 3);
        
        std::cout << form << std::endl;
        form.beSigned(clerk);
        std::cout << "After beSigned(): " << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
