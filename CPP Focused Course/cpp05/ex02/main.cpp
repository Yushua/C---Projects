/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/21 13:18:26 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_form(Form &form, Bureaucrat base)
{
	std::cout << "\n\n---------------------------------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "==execute form==" << std::endl;
	std::cout << form << std::endl;
	base.executeForm(form);
	std::cout << "---------------------------------" << std::endl;
	std::cout << "==sign " << base.getName() << "==" << std::endl;
	base.signForm(form);
	std::cout << form << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "==execute form for " << base.getName() << "==" << std::endl;//don't hardcode
	std::cout << form << std::endl;
	base.executeForm(form);
	std::cout << "---------------------------------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "---------------------------------\n\n" << std::endl;
}

int main()
{
	//now make test
	srand(time(NULL));
	try//try is only there to make the Bureaucrats
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "------ShrubberyCreationForm------" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		Bureaucrat yusha1("yusha", 120);//should work
		Bureaucrat flipy1("flipy", 150);//to low
		ShrubberyCreationForm form1("form1");
		test_form(form1, yusha1);
		std::cout << "=================================" << std::endl;
		// FLIPY EXEC MAG NIE

		test_form(form1, flipy1);
		std::cout << "---------------------------------" << std::endl;
		std::cout << "-------RobotomyRequestForm-------" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		Bureaucrat yusha2("yusha", 40);
		Bureaucrat flipy2("flipy", 150);
		RobotomyRequestForm form2("form2");
		RobotomyRequestForm roboform2("form2");
		flipy1.signForm(form2);
		flipy1.executeForm(form2);
		//just look into if every second time when executing would form robotomized
		test_form(form2, yusha2);
		test_form(form2, flipy2);
		std::cout << "---------------------------------" << std::endl;
		std::cout << "------PresidentialPardonForm-----" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		Bureaucrat yusha3("yusha", 1);
		Bureaucrat flipy3("flipy", 150);
		PresidentialPardonForm form3("form3");
		test_form(form3, yusha3);
		test_form(form3, flipy3);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	system("leaks Bureaucrat");
	return 0;
}
