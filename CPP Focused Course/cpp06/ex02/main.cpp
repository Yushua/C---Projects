/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 20:14:52 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/16 15:34:33 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int x = rand() % 3;
    if (x == 0)
    {
        return(new A);
    }
    else if (x == 1)
    {
        return(new B);
    }
    else
    {
        return(new C);
    }
    
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    Base tmp;
	try
	{
		tmp = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
    }
	try
	{
		tmp = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
    }
	try
	{
		tmp = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
    }
}

int main(void)
{
    srand(time(NULL));
    std::cout << "-----------------" << std::endl;
    Base* base1 = generate();
    std::cout << "no pointer" << std::endl;
    identify(base1);
    std::cout << "with pointer" << std::endl;
    identify(*base1);
    std::cout << "-----------------" << std::endl;
    Base* base2 = generate();
    std::cout << "no pointer" << std::endl;
    identify(base2);
    std::cout << "with pointer" << std::endl;
    identify(*base2);
    std::cout << "-----------------" << std::endl;
    return 0;
}