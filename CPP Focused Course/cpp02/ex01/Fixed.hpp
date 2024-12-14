/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/16 19:42:02 by ybakker       ########   odam.nl         */
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
        Fixed();
        Fixed(const Fixed &old_obj);
        Fixed(const int num);
		Fixed(const float num);  
        ~Fixed();
        Fixed& operator=(const Fixed &other);
        int		getFixed_point(void) const;
		void	setFixed_point(int const _fixed_point);
		float	toFloat(void) const;
		int		toInt(void) const;
    private:
        int		            _fixed_point;
        static const int	_factBits = 8;
};

std::ostream& operator<<(std::ostream & op, Fixed const & rhs);

#endif