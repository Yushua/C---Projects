/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/16 23:04:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <cstdlib>

class Bureaucrat
{
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
			GradeTooLowException();
			virtual ~GradeTooLowException() throw();
			virtual const char* what() const throw();
	};
	protected:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat& Bureaucrat);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();
		std::string const & getName() const;
		int getGrade() const;
		void increment();
		void decrement();
	
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif