/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 14:31:11 by ybakker       #+#    #+#                 */
/*   Updated: 2021/09/28 19:39:00 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;//adress
	std::string&	stringREF = str; //normal

	std::cout << &str << std::endl;//pointer
	std::cout << stringPTR<< std::endl;//adress
	std::cout << &stringREF << std::endl;//adress
	
	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
    return (0);
}
