/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/04 02:49:24 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/08 16:40:13 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H
# include <iostream>
# include <algorithm>

template <typename T>

int easyfind(T &container, int _input)
{
    typename T::iterator ptr;
    //need to find the value
    ptr = std::find(container.begin(), container.end(), _input);
    if (ptr == container.end())
    {
        throw std::runtime_error("Input could not be found");
    }
    return (*ptr);
}
#endif
