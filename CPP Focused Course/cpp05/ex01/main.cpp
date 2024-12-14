/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/21 13:18:49 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat* input(std::string name, int grade)
{
	try
	{
		return new Bureaucrat(name, grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}

int main()
{
	Bureaucrat Yusha("Yusha", 49);
	Form form("documents", false, 50, 50);//initialising it, so its filled and now under name form

	std::cout << form;
	std::cout << Yusha;
	std::cout << "---starting---" << std::endl;
	form.beSigned(Yusha);
	try
	{
		form.beSigned(Yusha);
		Yusha.signForm(form);
		Yusha.decrement();
		Yusha.decrement();
		std::cout << "------" << std::endl;
		form.beSigned(Yusha);
		Yusha.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	system("leaks Bureaucrat");
	return 0;
}
