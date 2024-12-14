/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 21:47:37 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/28 03:16:00 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void swap(T& x, T& y)//else it wont store
{
    T tmp = x;
    x = y;
    y = tmp;
}

template<typename T>
T min(T x, T y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

template<typename T>
T max(T x, T y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

#endif
