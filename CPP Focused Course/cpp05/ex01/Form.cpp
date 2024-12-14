/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 22:33:12 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/12 15:13:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _formName("Null"), _signed(false), _gradeSigned(0), _gradeExec(0)
{
	// std::cout << "Form is born" << std::endl;
}

Form::Form(std::string formName, bool signedd, int gradeSigned, int gradeExec): _formName(formName),_signed(signedd), _gradeSigned(gradeSigned), _gradeExec(gradeExec)
{
    this->_signed = false;
}

Form::Form(Form& copy): _formName(copy._formName), _signed(copy._signed), _gradeSigned(copy._gradeSigned), _gradeExec(copy._gradeExec)
{
	*this = copy;//so store a copy now from all these paramaters
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
}

std::string const & Form::getFormName() const 
{
    return this->_formName;
}

bool Form::getSigned() const 
{
    return this->_signed;
}

int Form::getGradeSigned() const 
{
    return this->_gradeSigned;
}

int Form::getGradeExec() const 
{
    return this->_gradeExec;
}

void Form::setSigned(bool value) {
	this->_signed = value;
}

void Form::beSigned(Bureaucrat& value)
{
    if (value.getGrade() >= this->_gradeSigned)
	{
		//i can place a do here where value.getGrade() turns false because now its too low
		//but the subject says I CAN'T do that
        throw GradeTooLowException();
	}
	else
		this->setSigned(true);
}

//so if it fails, i return this error in the mainin the catch, as its now stored
//https://www.geeksforgeeks.org/exceptionwhat-in-c-with-examples/
const char *Form::GradeTooHighException::what() const throw()
{
	return " grade is to high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is to low";
}

std::ostream& operator<<(std::ostream& out, const Form& src) {
	out << src.getFormName() << ", Sign Grade is " << src.getGradeSigned() << ", Execute Grade is " << src.getGradeExec();
	if (src.getSigned())
	{
		out << ", is signed" << std::endl;
	}
	else
	{
		out << ", is not signed" << std::endl;
	}
	return out;
}