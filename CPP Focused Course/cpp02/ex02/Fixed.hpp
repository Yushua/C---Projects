/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/16 19:44:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
    public:
        static Fixed& min(Fixed& fixPoint1, Fixed& fixPoint2);
        static Fixed& max(Fixed& fixPoint1, Fixed& fixPoint2);

        static const Fixed& min(const Fixed& fixPoint1, const Fixed& fixPoint2);
        static const Fixed& max(const Fixed& fixPoint1, const Fixed& fixPoint2);

        Fixed();                
        Fixed(const Fixed& src);
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();

        Fixed& operator=(const Fixed& rhs);
        //comparison operators
        int operator>(const Fixed& rhs);
        int operator<(const Fixed& rhs);
        int operator>=(const Fixed& rhs);
        int operator<=(const Fixed& rhs);
        int operator==(const Fixed& rhs);
        int operator!=(const Fixed& rhs);
        // arithmetic operators
        Fixed operator+(const Fixed& rhs);
        Fixed operator-(const Fixed& rhs);
        Fixed operator*(const Fixed& rhs);
        Fixed operator/(const Fixed& rhs);
        //increment/decrement
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        int getFixed_point(void) const;
        void setFixed_point(int const _fixed_point);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int		            _fixed_point;
        static const int	_factBits = 8;
};

std::ostream& operator<<(std::ostream& op, Fixed const& rhs);

#endif