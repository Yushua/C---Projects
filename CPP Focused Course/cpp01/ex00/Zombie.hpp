/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 14:31:29 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/15 22:20:08 by ybakker       ########   odam.nl         */
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
		void announce( void );
        Zombie(std::string name);
        ~Zombie();//name giving

};
Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
