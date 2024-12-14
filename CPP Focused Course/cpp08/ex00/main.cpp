/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/04 02:38:09 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/08 17:02:56 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <algorithm>
#include <ctime>

int main()
{
    std::srand(time(NULL));
    std::vector<int> _list;
    int y = 0;
	int size = 500;
    for(int i = 0; i < size; i++)
    {
        y = (std::rand() % size);
        _list.push_back(y);
    }
    std::cout << "[" << y << "]" << std::endl;
    std::cout << std::endl;
	std::cout << "values that are true" << std::endl;
	try
	{
		int x = 420;
		_list.push_back(x);
		std::cout << "input      : " << x << ": " << easyfind(_list, x) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    try
	{
		std::cout << "Wrong input: " << size + 1 << ": " << easyfind(_list, size + 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    try
	{
		int x = 303;
		_list.push_back(x);
		std::cout << "input      : " << x << ": " << easyfind(_list, x) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return (0);
}
