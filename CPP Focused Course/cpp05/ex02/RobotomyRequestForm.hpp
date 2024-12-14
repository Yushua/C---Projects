/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 02:52:40 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/15 15:20:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
class RobotomyRequestForm: public Form
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
    	RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        virtual ~RobotomyRequestForm();
        std::string const & getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
        
};

#endif