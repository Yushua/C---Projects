/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 21:45:06 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/05 21:56:04 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Array.hpp"
#include <cstring>

#define MAX_VAL 32
#define _VAL 30

int	main()
{
	std::cout << "------characters-----" << std::endl;
	Array<char>characters(5);
	for (int i = 0; i < 5; i++)
    {
		characters[i] = i  + 97;
		std::cout << "c["<< i <<"]: " << characters[i] << std::endl;
    }
	std::cout << "------integer--------" << std::endl;
	Array<int>	Test1(5);
	
	for (int i = 0; i < 5; i++)
    {
		Test1[i] = i  + 1;
		std::cout << "c["<< i <<"]: " << Test1[0] << std::endl;
    }
	std::cout << "------school---------" << std::endl;
    Array<int> numbers(_VAL);
    try
    {
        Array<int> numbers2(numbers);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "------school---------" << std::endl;
	// Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL || i < _VAL; i++)
    {
        int value = rand();
        try
        {
            numbers[i] = value;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        mirror[i] = value;
    }
    std::cout << "--------1----------" << std::endl;
    //SCOPE
    Array<int> tmp = numbers;
    Array<int> test(tmp);
    std::cout << "--------2----------" << std::endl;
    try
    {
        for (int i = 0; i < MAX_VAL || i < _VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------3----------" << std::endl;
    try
    {
        numbers[-2] = 0;//why do they do this tst
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------4----------" << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "--------end----------" << std::endl;
    delete [] mirror;//
    return 0;
}
