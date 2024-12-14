/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/05 00:40:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main()
{
    srand(time(NULL));
    Animal *Animals[10];
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0)
            Animals[i] = new Dog();
        else
            Animals[i] = new Cat();
    }
    std::cout << "------sound------" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        Animals[i]->makeSound();
        delete Animals[i];
    }
    Dog* dog = new Dog();
    Cat* cat = new Cat();

    std::cout << "------sound------" << std::endl;
    dog->makeSound();
    cat->makeSound();
    std::cout << "------------delete------------" << std::endl;
    delete dog;
    delete cat;
    // system("leaks eval");
}
