/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/21 13:18:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat* input(std::string name, int grade)
{
	try
	{
		return new (std::nothrow) Bureaucrat(name, grade);// what happens if this fails?
		//https://en.cppreference.com/w/cpp/memory/new/nothrow
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}

int main() {
	Bureaucrat alice("Alice", 5);
	Bureaucrat bob("Bob", 3);
	bob = alice;
	std::cout << bob.getName() << bob.getGrade() << std::endl;
	std::cout << "----------printing low and high--------" << std::endl;
	Bureaucrat* low = input("too high", 0);
	Bureaucrat* high = input("too low", 200);
	std::cout << "---------------------------" << std::endl;
	Bureaucrat* Yusha = input("Yusha", 2);
	Bureaucrat* Flipy = input("Flipy", 148);
	Bureaucrat me(*Yusha);

	(void)low;//call low
	(void)high;//call high
    std::cout << *Yusha;
	try
	{
		//make seperate fucntion, liek input. where I do the try
		Yusha->increment();
		
		Yusha->increment();
		Yusha->increment();
		Yusha->increment();

		Yusha->decrement();
		std::cout << "---decrease---" << std::endl;
		std::cout << *Yusha;
		Yusha->increment();
		std::cout << "---increase---" << std::endl;
		std::cout << *Yusha;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;//if called, do this
	}
	std::cout << "---------------------------" << std::endl;
	std::cout << *Flipy;
	try
	{
		Flipy->decrement();
		std::cout << *Flipy;
		Flipy->decrement();
		std::cout << *Flipy;
		Flipy->decrement();
		std::cout << *Flipy;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete Yusha;
	delete Flipy;
	system("leaks Bureaucrat");
	return 0;
}
