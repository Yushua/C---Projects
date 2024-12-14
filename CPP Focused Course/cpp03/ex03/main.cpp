/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 18:01:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
	srand(999);
	DiamondTrap	yusha("yusha");
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	yusha.whoAmI();
	yusha.highFivesGuys();
	yusha.guardGate();
	yusha.attack("bandit");
	yusha.takeDamage(100);
	yusha.takeDamage(50);
	yusha.beRepaired(0);
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
}
