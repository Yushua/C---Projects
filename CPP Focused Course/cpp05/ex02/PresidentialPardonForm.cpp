/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 02:52:34 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/15 15:22:42 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", false, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential Pardon Form", false, 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{
	// std::cout << "Copy Constructor called" << std::endl;
	this->_target = copy.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "Destructor called" << std::endl;
}

std::string const & PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
