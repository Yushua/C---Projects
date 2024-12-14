/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/16 19:45:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	learning how operator work
*/

Fixed::Fixed()
{s
	_fixed_point = 0;
}

Fixed::Fixed(const Fixed& old_obj)
{
	_fixed_point = old_obj._fixed_point;
}

Fixed::Fixed(const int num)
{
	_fixed_point = num << Fixed::_factBits;
}

Fixed::Fixed(const float num)
{
	_fixed_point = roundf(num * (1 << Fixed::_factBits));
}

Fixed::~Fixed()
{
	
}

int Fixed::getFixed_point(void) const
{
	return (_fixed_point);
}

void Fixed::setFixed_point(int const new_val)
{
	_fixed_point = new_val;
}

float Fixed::toFloat(void) const
{
  	return ((float)_fixed_point / (1 << Fixed::_factBits));
}

int Fixed::toInt(void) const
{
	return (_fixed_point >> Fixed::_factBits);
}

Fixed& Fixed::min(Fixed& fixPoint1, Fixed& fixPoint2)
{
	if (fixPoint1._fixed_point < fixPoint2._fixed_point)//fixed
		return (fixPoint1);
  	return (fixPoint2);
}

Fixed& Fixed::max(Fixed& fixPoint1, Fixed& fixPoint2)
{
  	if (fixPoint1._fixed_point > fixPoint2._fixed_point)
	  	return (fixPoint1);
  	return (fixPoint2);
}

const Fixed& Fixed::min(const Fixed& fixPoint1, const Fixed& fixPoint2)
{
  	if (fixPoint1._fixed_point < fixPoint2._fixed_point)//const
	  	return (fixPoint1);
  	return (fixPoint2);
}

const Fixed& Fixed::max(const Fixed& fixPoint1, const Fixed& fixPoint2)
{
  	if (fixPoint1._fixed_point > fixPoint2._fixed_point)
	  	return (fixPoint1);
  	return (fixPoint2);
}

/*  Six comparison operators */
int Fixed::operator>(const Fixed& rhs)
{
  	if (this->_fixed_point > rhs.getFixed_point())
	  	return (1);
  	return (0);
}

int Fixed::operator<(const Fixed& rhs)
{
  	if (this->_fixed_point < rhs.getFixed_point())
	  	return (1);
  	return (0);
}

int Fixed::operator>=(const Fixed& rhs)
{
  	if (this->_fixed_point >= rhs.getFixed_point())
	  	return (1);
  	return (0);
}

int Fixed::operator<=(const Fixed& rhs)
{
  	if (this->_fixed_point <= rhs.getFixed_point())
	  	return (1);
  	return (0);
}

int Fixed::operator==(const Fixed& rhs)
{
  	if (this->_fixed_point == rhs.getFixed_point())
	  	return (1);
  	return (0);
}

int Fixed::operator!=(const Fixed& rhs)
{
  	if (this->_fixed_point != rhs.getFixed_point()) 
	  	return (1);
  	return (0);
}

/*  Four arithmetic operators */

Fixed Fixed::operator+(const Fixed& rhs)
{
  	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed& rhs)
{
  	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed& rhs)
{
  	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed& rhs)
{
  	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++()
{
  this->_fixed_point++;
  return (*this);
}

Fixed Fixed::operator++(int)
{
  Fixed tmp = *this;
  ++*this;
  return (tmp);
}

Fixed& Fixed::operator--()
{
  	this->_fixed_point--;
  	return (*this);
}

Fixed Fixed::operator--(int)
{
  	Fixed tmp = *this;
  	--*this;
	return (tmp);
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
  	if (this == &rhs)
	  	return (*this);
  	_fixed_point = rhs._fixed_point;
  	return (*this);
}

std::ostream& operator<<(std::ostream& op, Fixed const& rhs)
{
  	op << rhs.toFloat();
  	return (op);
}