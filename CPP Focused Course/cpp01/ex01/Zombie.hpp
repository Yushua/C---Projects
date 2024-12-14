/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 14:31:29 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/17 12:41:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string.h>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
        Zombie(std::string name);
        ~Zombie();//name giving
		void	setName(std::string name);
		void	announce( void );

};

Zombie*	zombieHorde(int N, std::string name);
#endif