/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/16 22:25:51 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(Dog& copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Assignation Operator called" << std::endl;
	_type = copy._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "WOOF!!!" << std::endl;
}