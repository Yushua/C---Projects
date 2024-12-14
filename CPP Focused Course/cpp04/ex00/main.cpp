/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/05 00:44:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main(void)
{
		std::cout << "------create------" << std::endl;
		const Animal* animal = new Animal();
		std::cout << "------dog------" << std::endl;
		const Animal* dog = new Dog();
		std::cout << "------cat------" << std::endl;
		const Animal* cat = new Cat();
		const WrongAnimal* wrong = new WrongCat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << "------sound------" << std::endl;
		cat->makeSound();
		dog->makeSound();
		animal->makeSound();
		wrong->makeSound();
		std::cout << "------delete------" << std::endl;
		delete animal;
		delete cat;
		delete dog;
		delete wrong;
}
