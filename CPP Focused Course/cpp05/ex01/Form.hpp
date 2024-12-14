/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 22:33:09 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/31 17:41:26 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <string>
#include <iostream>
#include <cstdlib>

# include "Bureaucrat.hpp"

class Form
{
    
	private://can only be acces by functions in this class
        std::string const _formName;
        bool _signed;
        int const _gradeSigned;
        int const _gradeExec;
	public:
    	Form();
		Form(std::string formName, bool signed_, int _gradeSigned, int _gradeExec);
		Form(Form& Form);
		Form& operator=(const Form& copy);
		~Form();
	
        std::string const & getFormName() const;
        bool getSigned() const ;
        int getGradeSigned() const ;
        int getGradeExec() const;
		void setSigned(bool is);
        void beSigned(Bureaucrat& value);
		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException();
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException() {}
				virtual ~GradeTooLowException() throw() {}
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif