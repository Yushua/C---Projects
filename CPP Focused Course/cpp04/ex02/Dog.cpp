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
#include "Brain.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog& copy): Animal(copy)
{
	*this = copy;
}

Dog::~Dog()
{
	delete _brain;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		this->~Dog();
		this->_brain = new Brain(*copy.getBrain());
		this->Animal::operator=(copy);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << GREEN << "WOOF!!!" << RESET << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}
