/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 01:09:35 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 14:52:10 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_colour = this->getColour();
	_name = "Handsome_Frag";
	_hp = 100;
	_ep = 100;
	_attack_dmg = 30;
	std::cout << "\nwelcome to the borderlands Default FragTrap\n"
	<< "just go and blow yourself up\n\n"
	<< "so your name is " << _colour << _name << RESET << ". Well I have seen weirder. "
	<< "welcome to Pandora.\n" << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	_colour = this->getColour();
	_name = name;
	_hp = 100;
	_ep = 100;
	_attack_dmg = 30;
	std::cout << "\nwelcome to the borderlands FragTrap\n"
	<< "just go and blow yourself up\n\n"
	<< "so your name is " << _colour << _name << RESET << ". Well I have seen weirder. "
	<< "welcome to Pandora.\n" << std::endl;
}

FragTrap::FragTrap( const FragTrap &copy)
{
	*this = copy;
	std::cout << BLUE << "We got ourselves a Fragtrap\n" << RESET << std::endl;
}

FragTrap::~FragTrap() 
{
	std::cout << "FragTrap " << this->_colour << this->_name << RESET << " not again, i swear that I would never use a coupon for these things " << RED << "NEVER!!! " << RESET << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_attack_dmg = other._attack_dmg;		
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->_colour << this->_name << RESET << MAGENTA ": High five guys!!  ....  guys?..." << RESET << std::endl;
}
