/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 19:40:48 by ybakker       #+#    #+#                 */
/*   Updated: 2021/10/01 13:51:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

HumanB::HumanB(std::string name)
{
    this->_name = name;//to store
    return ;
}

HumanB::~HumanB()
{
    return ;
}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with this awesome weapon named " << RED << this->_arm->getType() << RESET << std::endl;
    return ;
}

void HumanB::setWeapon(Weapon& arm)
{
    this->_arm = &arm;
    return ;
}
