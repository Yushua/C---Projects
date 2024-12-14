/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 00:20:19 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/01 14:47:25 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

class ClapTrap
{
	protected:
		std::string	_name,
					_colour;
		int			_hp;
		int			_ep;
		int			_attack_dmg;
	public:
		ClapTrap();
		ClapTrap(const std::string	name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap &other);
		//function
		std::string	getColour();
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
