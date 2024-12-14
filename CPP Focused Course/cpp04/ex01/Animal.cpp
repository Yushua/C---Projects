/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/03 19:00:13 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "animal is born" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	_type = copy._type;
}

Animal::~Animal()
{
	std::cout << "Animal is dead" << std::endl;
}

Animal&	Animal::operator=(const Animal &copy)
{
	this->_type = copy._type;
	return (*this);
}

std::string const & Animal::getType() const
{
	std::cout << "getType member function called" << std::endl;
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal Animal!!!" << std::endl;
}
