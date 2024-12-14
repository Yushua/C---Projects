/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/03 14:54:04 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "Null";
}

Animal::Animal(Animal& copy)
{
	_type = copy._type;
}

Animal::~Animal()
{
	std::cout << "Animal is dead" << std::endl;
}

Animal&	Animal::operator=(const Animal &copy)
{
	_type = copy._type;
	return (*this);
}

const std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "no sound" << std::endl;
}
