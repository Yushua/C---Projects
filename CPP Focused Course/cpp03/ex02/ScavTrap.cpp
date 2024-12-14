/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 00:44:17 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 17:56:37 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

ScavTrap::ScavTrap()
{
	_colour = this->getColour();
	std::cout << "\nwelcome to the borderlands Default ScavTrap" << std::endl
	<< "so your ScavTrap name is " << _colour << _name << RESET << " pretty exspensive for a Scav like you\n" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) 
{
	_name = name + " Scav ";
	_hp = 100;
	_ep = 50;
	_attack_dmg = 20;
	_colour = this->getColour();
	std::cout << "\nwelcome to the borderlands ScavTrap" << std::endl
	<< "so your ScavTrap name is " << this->_colour << this->_name << RESET << " pretty expensive for a Scav like you\n" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &copy)
{
	*this = copy;
    std::cout << GREEN<< "We got ourselves a ScavTrap\n" << RESET << std::endl;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap " << this->_colour << this->_name << RESET << " is down on its luck, i am sure it is " << RED << "SABOTAGE\n" << RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	this->ClapTrap::operator=(other);
	return (*this);
}

void		ScavTrap::attack(std::string const & target)
{
	if (this->_ep > 0)
	{
		if (this->_hp <= 0)
		{
			std::cout << "ScavTrap " << this->_name << " is out of hit points! you can't kick a dead horse in this town" << std::endl;
		}
		else
		{
			std::cout	<< "ScavTrap " << this->_colour << this->_name << RESET << " attacks with range and hits " << target << "with " << this->_attack_dmg << "." << std::endl;
			this->_ep -= 1;
		}
	}
	else
		std::cout	<< "ScavTrap " << this->_colour << this->_name << RESET << " has not been able to " << RED << "attack" << RESET << " due to lack of energy " << std::endl;
}

void ScavTrap::guardGate()
{
  std::cout << BLUE << this->_name << " is now in 'Gate Keeper' mode.\n" << RESET<< std::endl;
}
