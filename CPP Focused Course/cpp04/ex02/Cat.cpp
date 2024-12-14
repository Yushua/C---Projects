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
#include "Brain.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat& copy): Animal(copy)
{
	*this = copy;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat has died" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		this->~Cat();
		this->_brain = new Brain(*copy.getBrain());
		this->Animal::operator=(copy);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << BLUE << "Meow!!!" << RESET << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}
