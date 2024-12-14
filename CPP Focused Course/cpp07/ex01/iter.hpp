/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 21:47:37 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/28 18:09:00 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T* ptr, int lenght, void (*za)(const T &))//else it wont store
{
    for(int i = 0; i < lenght; i++)
    {
        za(ptr[i]);
    }
}

template <typename T>
void	ft_write(const T &string){
	std::cout << string << std::endl;
}

#endif
