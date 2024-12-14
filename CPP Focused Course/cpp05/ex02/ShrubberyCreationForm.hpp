/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 02:52:45 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/24 05:04:09 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
    	ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        virtual ~ShrubberyCreationForm();
        std::string const & getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
        
};

#endif