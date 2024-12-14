/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2021/11/05 23:14:59 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

Fixed::Fixed( )
{
	_fixed_point = 0;
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed( const Fixed &old_obj)
{
	*this = old_obj;
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << BLUE << "Assignment operator called" << RESET << std::endl;
	_fixed_point = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	return (_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point = raw;
	std::cout << GREEN << "setRawBits member function called" << RESET << std::endl;
}
