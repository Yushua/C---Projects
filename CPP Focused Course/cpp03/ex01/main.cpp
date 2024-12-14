/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 14:54:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
    srand(time(0));
    ScavTrap* scavy = new ScavTrap("Scavenger");
    
    scavy->attack("Big Bandit");
    scavy->takeDamage(3);
    scavy->beRepaired(2);
    delete scavy;
    std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;

    srand(time(0));
    ScavTrap* scavtrap = new ScavTrap;
    scavtrap->attack("Big Enemy");
    scavtrap->takeDamage(3);
    scavtrap->beRepaired(2);
    scavtrap->takeDamage(4);
    scavtrap->attack("Enemy");
    scavtrap->guardGate();
    delete scavtrap;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}
