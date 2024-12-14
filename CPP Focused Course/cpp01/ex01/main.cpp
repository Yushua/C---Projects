/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 14:31:11 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/17 12:46:39 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	
    Zombie *zombies;
	int x = 5;
	zombies = zombieHorde(x, "Flipy");//make new zombie on this name
    for (int i = 0; i < x; i++)
    {
		zombies[i].announce();
	}
	delete[] zombies;
    return (0);
}
