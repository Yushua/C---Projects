/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 01:33:35 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 18:00:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_attack_dmg = FragTrap::_attack_dmg;
	this->_colour = this->getColour();
	std::cout << "\nwelcome to the borderlands D..d..ddd.....DIAMOND\n"
	<< "so your DIAMOND name is " << this->_colour << this->_name << RESET << ". wow how expensive. "
	<< "welcome to Pandora PRECIOUS.\n" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap::ClapTrap(name), FragTrap::FragTrap(name),ScavTrap::ScavTrap(name) 
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_attack_dmg = FragTrap::_attack_dmg;
	this->_colour = this->getColour();
	std::cout << "\nwelcome to the borderlands D..d..ddd.....DIAMOND\n"
	<< "so your DIAMOND name is " << this->_colour << this->_name << RESET << ". wow how expensive. "
	<< "welcome to Pandora PRECIOUS \n" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &copy)
{
	*this = copy;
	std::cout << RED << "We got ourselves a DiamondTrap\n" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() 
{
	std::cout << "Diamond-TP " << this->_colour << this->_name << RESET << " DIAMONDS SHOULD BE TOUGH, HWO COUlD THIS HAPPEN TO ME? I MADE NO MISTAKES " << RED << "NEVER!!! DESTROYED!!!" << RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other)
{
	this->ClapTrap::operator=(other);
	this->_name = other._name;	
	return (*this);
}

std::string		DiamondTrap::getColour()
{
	int x = rand() % 4;
	std::string colours[] = {
		RED, 
		GREEN, 
		BLUE, 
		MAGENTA, 
		CYAN};
	return (colours[x]);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "whoami " << YELLOW << this->_name << RESET << " and my diamondTrap name is " << YELLOW << ClapTrap::_name << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	return ;
}

