/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/05 00:47:33 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int y = 6;
    Animal *Animals[y];
    for (int i = 0; i < y; ++i)
    {
        if (i % 2 == 0)
        {
            Animals[i] = new Dog();
            Animals[i]->makeSound();
        }
        else
        {
            Animals[i] = new Cat();
            Animals[i]->makeSound();
        }
    }
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < y; ++i)
        delete Animals[i];
    std::cout << "------------------------" << std::endl;
    
    Dog tmp;
    Dog basic = tmp;
    std::cout << "------next1------" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << ": " << basic.getBrain()->getIdeas(i) << "     " << std::endl;
    }
    std::cout << "------next------" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << ": " << basic.getBrain()->getIdeas(i) << "     " << std::endl;
    }
    std::cout << "------next------" << std::endl;
}
