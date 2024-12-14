/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/04 02:38:09 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/08 16:59:05 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <ctime>

//used to know if a number I add is already in there

int main()
{
    std::cout << "\n|---correct---|" << std::endl;
    try
    {
        std::cout << "--should be 2--" << std::endl;
        Span _list = Span(5);
        _list.addNumber(1);
        _list.addNumber(3);
        _list.addNumber(5);
        _list.addNumber(7);
        _list.addNumber(9);
        std::cout << "shortest :" << _list.shortestSpan() << std::endl;
        std::cout << "Longest  :" <<_list.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n|---mistake---|" << std::endl;
    try
    {
        std::cout << "---innitiate---\n" << std::endl;
        Span _try = Span(0);
        std::cout << "---add---\n" << std::endl;
        _try.addNumber(1);
        std::cout << "---short---" << std::endl;
        std::cout << "shortest :" << _try.shortestSpan() << std::endl;
        std::cout << "---long---" << std::endl;
	    std::cout << "Longest  :" << _try.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n|---correct---|" << std::endl;
    try
    {
        int leng = 5;
        int x = 1;
        int y = 300;
        std::cout << "--should be " << leng << "--" << std::endl;
        Span _list = Span(y);
        for(int z = 0; z < y; z++)
        {
            _list.addNumber(x + leng);
            x+= leng;
        }
        std::cout << "shortest :" << _list.shortestSpan() << std::endl;
        std::cout << "Longest  :" <<_list.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
