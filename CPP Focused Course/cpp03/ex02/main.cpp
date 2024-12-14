/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 14:56:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
    srand(time(0));
    FragTrap *fragy = new FragTrap("Fragy");

    fragy->attack("Bandit");
    fragy->takeDamage(3);
    fragy->beRepaired(2);
    std::cout << std::endl;
    srand(time(0));
    FragTrap *dummy = new FragTrap(*fragy);
    dummy->highFivesGuys();
    delete dummy;
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    srand(time(0));
    ScavTrap *fragtrap = new ScavTrap;
    fragtrap->attack("Bandit");
    fragtrap->takeDamage(3);
    fragtrap->beRepaired(2);
    fragtrap->takeDamage(4);
    fragtrap->attack("student");
    fragtrap->guardGate();
    delete fragtrap;
    std::cout << std::endl;
    delete fragy;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}
