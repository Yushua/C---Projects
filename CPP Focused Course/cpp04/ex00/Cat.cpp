/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/16 22:25:51 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(Cat& copy)
{
	std::cout << " Cat Copy Constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Assignation Operator called" << std::endl;
	_type = copy._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!!!" << std::endl;
}
