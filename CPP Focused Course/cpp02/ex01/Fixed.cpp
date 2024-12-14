/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2021/11/05 23:59:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
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

Fixed::Fixed(const Fixed &old_obj)
{
	*this = old_obj;
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int num) //int
{
	std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
	_fixed_point = num << Fixed::_factBits;
}

Fixed::Fixed(const float num)//float
{
	std::cout << YELLOW << "Float constructor called" << RESET << std::endl;
	_fixed_point = roundf(num * (1 << Fixed::_factBits));
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other)//so changing a private operator
{
	std::cout << BLUE << "Assignment operator called" << RESET << std::endl;
	_fixed_point = other._fixed_point;
	return (*this);
}

/*
writing it on the OS stream and turn it in
this took me a while to understand, I just forgot the << and did not understand it
now I know how it works, but I leave this comment here to remind myself
*/

std::ostream& operator<<(std::ostream& op, Fixed const& rhs)
{
	op << rhs.toFloat();
	return (op);
}

int	Fixed::getFixed_point(void) const
{
	return (_fixed_point);
}

void	Fixed::setFixed_point(int const new_fixed_point)
{
	_fixed_point = new_fixed_point;
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixed_point / (1 << Fixed::_factBits));
}

int		Fixed::toInt(void) const
{
	return (_fixed_point >> Fixed::_factBits);
}
