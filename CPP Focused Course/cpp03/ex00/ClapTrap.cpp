/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 17:55:44 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "Handsome_Jack";
	_hp = 10;
	_ep = 10;
	_attack_dmg = 0;
	_colour = this->getColour();
	std::cout << "\nwelcome to the borderlands default Claptrap, hope you survive longer than the last one!\ni will now start my automatic greetings process\n"
	<< "wait your colour is NOT yellow??? Yellow is the way to go\n\n"
	<< "so your name is " << _colour << _name << RESET << ". Well I have seen weirder. "
	<< "welcome to Pandora.\n" << std::endl;
}

ClapTrap::ClapTrap(const std::string name): _name(name)
{
	_colour = this->getColour();
	_hp = 10;
	_ep = 10;
	_attack_dmg = 0;
	std::cout << "\nwelcome to the borderlands Claptrap, hope you survive longer than the last one!\ni will now start my automatic greetings process\n"
	<< "wait your colour is NOT yellow??? Yellow is the way to go\n\n"
	<< "so your name is " << _colour << _name << RESET << ". Well I have seen weirder. "
	<< "welcome to Pandora.\n" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap " << _colour << _name << RESET << " has died, oh no!!! what has gone from a simple fight between friends has become " << RED << "MURDER " << RESET << std::endl;
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

/* in the subject it says that my attack needs to damage the target, BUT because its a string, i cannot do this
see when I make a Claptrap bandit and give it here (so i made something my claptrap can attack
then i get this error
main.cpp:23:16: error: reference to type 'const std::string' (aka 'const basic_string<char, char_traits<char>, allocator<char> >') could not bind to an lvalue of type 'ClapTrap *'
        yusha->attack(bandit);
                      ^~~~~~
./ClapTrap.hpp:47:34: note: passing argument to parameter 'target' here
                void    attack(std::string const &target);

because the Claptrap is not something that can me targeted
*/

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
		std::cout<< "ClapTrap " << this->_colour << this->_name << RESET << " has taken " << (oldhp - this->_hp) << " damage." << std::endl;
		std::cout << "oh dear ClapTrap " << this->_colour << this->_name << RESET << " is now at " << this->_hp << " health." << std::endl;
	}
	else
	{
		std::cout << "oh dear ClapTrap " << this->_colour << this->_name << RESET << " is already at " << this->_hp << " you're unable to damage anymore " << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	int oldhp = this->_hp;
	if (this->_ep > 0)
	{
		this->_ep -= 1;
		this->_hp += amount;
		std::cout	<< "ClapTrap " << this->_colour << this->_name << RESET << " repaired himself with " << (this->_hp - oldhp) << " hit points! WOOOHOOO" << std::endl;
	}
	else
		std::cout	<< "ClapTrap " << this->_colour << this->_name << RESET << " has not been able to repair itself due to lack of energy " << std::endl;
}
