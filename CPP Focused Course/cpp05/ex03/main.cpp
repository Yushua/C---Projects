/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/21 13:19:01 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void test_form(Form &form, Bureaucrat &Yusha, Bureaucrat &Flipy)
{
	Flipy.signForm(form);
	std::cout << std::endl;
	Flipy.executeForm(form);
	std::cout << std::endl;
	Yusha.signForm(form);
	std::cout << std::endl;
	Yusha.executeForm(form);
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));
	Bureaucrat Yusha("Yusha", 1);
	Bureaucrat Flipy("Flipy", 150);
	Intern intern;
	Form *form;
	std::cout << "----0-----" << std::endl;
	try
	{
		form = intern.makeForm("shrubbery", "home");
		test_form(*form, Yusha, Flipy);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----1-----" << std::endl;
	try
	{
		form = intern.makeForm("robotomy", "WooongChicken");
		test_form(*form, Yusha, Flipy);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----2-----" << std::endl;
	try
	{
		form = intern.makeForm("Presidential Pardon Form", "nope");
		test_form(*form, Yusha, Flipy);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----3-----" << std::endl;
	try
	{
		form = intern.makeForm("Flipy Failure", "target");
		test_form(*form, Yusha, Flipy);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	system("leaks Bureaucrat");
	return (0);
}
