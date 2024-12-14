/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 21:45:06 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/28 18:09:10 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include <unistd.h>
#include "iter.hpp"

int	main()
{
	int _array_nb[] = {1,2, 3, 4, 5};
	iter(_array_nb, sizeof(_array_nb)/sizeof(*_array_nb), ft_write);
    std::cout <<"------------------" << std::endl;
	std::string _array_string[] = {"codam","COLLEGE", "42"};
	iter(_array_string, sizeof(_array_string)/sizeof(*_array_string), ft_write);
    std::cout <<"------------------" << std::endl;
	bool _array_bool[] = {true,false};
	iter(_array_bool, sizeof(_array_bool)/sizeof(*_array_bool), ft_write);
    std::cout <<"------------------" << std::endl;
	return 0;
}
