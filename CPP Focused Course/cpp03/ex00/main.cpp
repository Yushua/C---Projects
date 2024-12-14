/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 17:54:53 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <time.h>

int main(void)
{
	srand(time(0));
	ClapTrap *yusha = new ClapTrap("yusha");
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	yusha->attack("bandit");
	yusha->takeDamage(5);
	yusha->beRepaired(5);
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	delete yusha;

}
