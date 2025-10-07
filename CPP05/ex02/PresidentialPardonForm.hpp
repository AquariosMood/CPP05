/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:47:31 by crios             #+#    #+#             */
/*   Updated: 2025/07/12 15:39:47 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        // PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm & other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm & other);
        ~PresidentialPardonForm();

        std::string getTarget() const;
    //    void execute(Bureaucrat &executor) const;
        void beSigned(Bureaucrat &bureaucrat);
        
        void execute(Bureaucrat &executor) const;
};

# endif