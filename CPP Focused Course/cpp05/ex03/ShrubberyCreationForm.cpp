/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 02:52:42 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/15 15:26:56 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Request Form", false, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery Request Form", false, 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	// std::cout << "Copy Constructor called" << std::endl;
	this->_target = copy.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "Destructor called" << std::endl;
}

std::string const & ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::cout << "                            '., " << std::endl;
	std::cout << "                              'b      *" << std::endl;
	std::cout << "                               '$    #." << std::endl;
	std::cout << "                                $:   #:" << std::endl;
	std::cout << "                                *#  @):" << std::endl;
	std::cout << "                                :@,@):   ,.**:'" << std::endl;
	std::cout << "                      ,         :@@*: ..**'" << std::endl;
	std::cout << "                       '#o.    .:(@'.@*'' " << std::endl;
	std::cout << "                          'bq,..:,@@*'   ,*" << std::endl;
	std::cout << "                          ,p$q8,:@)'  .p*'" << std::endl;
	std::cout << "                         '    '@@Pp@@*'" << std::endl;
	std::cout << "                               Y7'.'" << std::endl;
	std::cout << "                              :@):." << std::endl;
	std::cout << "                             .:@:'." << std::endl;
	std::cout << "                           .::(@:." << std::endl;
}

Form* ShrubberyCreationForm::clone(void) const
{
	ShrubberyCreationForm *clone = new ShrubberyCreationForm(*this);
	return clone;
}
