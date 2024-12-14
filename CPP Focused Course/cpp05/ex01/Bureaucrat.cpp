/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/18 01:42:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

Bureaucrat::Bureaucrat(): _name(NULL), _grade(0)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name)
{
	*this = copy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string const & Bureaucrat::getName() const
{
	return(this->_name);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::increment()
{
	try
	{
		if (--this->_grade < 1)
		{
			this->_grade++;
			throw GradeTooHighException();
		}
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
void Bureaucrat::decrement()
{
	try
	{
		if (++this->_grade > 150)
		{
			this->_grade--;
			throw GradeTooLowException();
		}
	}
	catch(GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

//so if it fails, i return this error in the mainin the catch, as its now stored
Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade to high, can not be higher than 1";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade to low, can not be lower than 150";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src) {
	std::cout << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return out;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getFormName() << std::endl;
	}
	catch(const std::exception& e)//this is the current throw
	{
		//just check why it can not be signed, probably with the next ones
		std::cerr << this->getName() << " cannot sign " << form.getFormName() << " because sign grade is too low." << std::endl;
		std::cerr << e.what() << std::endl;
	}
}
