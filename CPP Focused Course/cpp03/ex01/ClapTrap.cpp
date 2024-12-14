/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 17:49:04 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

ClapTrap::ClapTrap()
{
	_name = "Handsome_Jack";
	_hp = 10;
	_ep = 10;
	_attack_dmg = 0;
	_colour = this->getColour();
	std::cout << "\nwelcome to the borderlands default Claptrap, hope you survive longer than the last one!\ni will now start my automatic greetings process\n"
	<< "wait your colour is NOT yellow??? Yellow is the way to go\n\n"
	<< "so your ClapTrap name is " << _colour << _name << RESET << ". Well I have seen weirder. "
	<< "welcome to Pandora.\n" << std::endl;
}

ClapTrap::ClapTrap(const std::string name): _name(name)
{
	_hp = 10;
	_ep = 10;
	_attack_dmg = 0;
	_colour = this->getColour();
	std::cout << "\nwelcome to the borderlands Claptrap, hope you survive longer than the last one!\ni will now start my automatic greetings process\n"
	<< "wait your colour is NOT yellow??? Yellow is the way to go\n\n"
	<< "so your ClapTrap name is " << this->_colour << _name << RESET << ". Well I have seen weirder. "
	<< "welcome to Pandora.\n" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy)
{
	*this = copy;
	std::cout << YELLOW << "We got ourselves a claptrap\n" << RESET << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap " << this->_colour << this->_name << RESET << " has died, oh no!!! what has gone from a simple fight between friends has become " << RED << "MURDER " << RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_attack_dmg = other._attack_dmg;		
	return (*this);
}

std::string		ClapTrap::getColour()
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

void		ClapTrap::attack(std::string const & target)
{
	if (this->_ep > 0)
	{
		if (this->_hp <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " is out of hit points! you can't kick a dead horse in this town" << std::endl;
		}
		else
		{
			std::cout	<< "ClapTrap " << this->_colour << this->_name << RESET << " attacks with range and hits " << target << "with " << this->_attack_dmg << "." << std::endl;
			this->_ep -= 1;
		}
	}
	else
		std::cout	<< "ClapTrap " << this->_colour << this->_name << RESET << " has not been able to " << RED << "attack" << RESET << " due to lack of energy " << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	int	oldhp = _hp;
	this->_hp -= amount;
	if (this->_hp < 0)
	{
		this->_hp = 0;
		std::cout	<< "ClapTrap " << this->_colour << this->_name << RESET << " has taken " << (oldhp - this->_hp) << " damage." << std::endl;
		std::cout << "oh dear ClapTrap " << this->_colour << this->_name << RESET << " is now at " << this->_hp << " health." << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	int oldhp = this->_hp;
	if (this->_ep > 0)
	{
		this->_ep -= 1;
		this->_hp += amount;
		std::cout	<< "ClapTrap " << this->_colour << this->_name << RESET << " repaired themselves with " << (this->_hp - oldhp) << " hit points! WOOOHOOO" << std::endl;
	}
	else
		std::cout	<< "ClapTrap " << this->_colour << this->_name << RESET << " has not been able to repair itself due to lack of energy " << std::endl;
}
