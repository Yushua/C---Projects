/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/06 16:26:02 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "wrong animal constructed" << RESET << std::endl;
	_type = "Wrong Animal";
}

WrongAnimal::WrongAnimal(WrongAnimal& copy)
{
	std::cout << GREEN << "Copy Constructor called" << RESET << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "Assignation Operator called" << std::endl;
	this->_type = copy.getType();
	return (*this);
}

const std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout << "ANIMAL IS WRONG WRONG WRONG" << std::endl;
}
