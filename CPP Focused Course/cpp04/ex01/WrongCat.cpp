/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/06 16:25:44 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << YELLOW << "WRONG CAT" << RESET<< std::endl;
	_type = "Wrong Cat";
}

WrongCat::WrongCat(WrongCat& copy)
{
	std::cout << YELLOW << "Copy Constructor called" << RESET<< std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "Assignation Operator called" << std::endl;
	this->_type = copy.getType();
	return (*this);
}

const std::string  WrongCat::getType(void) const
{
	std::cout << "getType member function called" << std::endl;
	return (this->_type);
}

void WrongCat::makeSound() const
{
	std::cout << "THIS IS THE WRONG CAT" << std::endl;
}
