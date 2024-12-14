/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 14:36:31 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/17 13:11:33 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"//get the randomchump from zombie

void randomChump( std::string name )
{
    Zombie zombie(name);
    zombie.announce();
}
