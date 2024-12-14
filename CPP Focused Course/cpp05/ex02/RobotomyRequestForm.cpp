/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 02:52:37 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/15 15:22:05 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", false, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy Request Form", false, 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
	// std::cout << "Copy Constructor called" << std::endl;
	this->_target = copy.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	// std::cout << "Assignation Operator called" << std::endl;
	if (this != &copy)
	{
		this->_target = copy.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Destructor called" << std::endl;
}

std::string const & RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::cout << "Drill noises" << std::endl;
	int number = rand() % 2;
	if (number % 2 == 0) //rand will always be the same number, therefore it will never change even if u call it 4 times,
	{
		std::cout << this->_target << "Has been succesfully robotomized" << std::endl;
		number ++;
	}
	else
	{
		std::cout << this->_target << "Has not been succesfully robotomized" << std::endl;
		number ++;
	}
}
