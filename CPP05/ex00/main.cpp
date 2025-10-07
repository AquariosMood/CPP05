/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:42 by crios             #+#    #+#             */
/*   Updated: 2025/08/30 10:50:05 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Test 1: Normal bureaucrat creation and operations ===" << std::endl;
    try 
    {
        Bureaucrat bureaucrat("John", 75);
        std::cout << bureaucrat << std::endl;
        
        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;
        
        bureaucrat.decrementGrade();
        std::cout << "After decrement: " << bureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high at construction ===" << std::endl;
    try 
    {
        Bureaucrat bureaucrat("Bob", 0);
        std::cout << bureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low at construction ===" << std::endl;
    try 
    {
        Bureaucrat bureaucrat("Alice", 151);
        std::cout << bureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment beyond maximum grade ===" << std::endl;
    try 
    {
        Bureaucrat bureaucrat("Max", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrement beyond minimum grade ===" << std::endl;
    try 
    {
        Bureaucrat bureaucrat("Min", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
    try 
    {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
