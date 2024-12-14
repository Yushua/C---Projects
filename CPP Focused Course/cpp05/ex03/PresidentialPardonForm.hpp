/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 02:52:30 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/12 16:56:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
    	PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        virtual ~PresidentialPardonForm();
        std::string const & getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
        virtual Form* clone(void) const;
};

#endif