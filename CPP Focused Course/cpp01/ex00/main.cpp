/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 14:31:11 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/17 13:08:39 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie zombie("Flip");

    Zombie *zombienew = newZombie("Sinterklaas");//make new zombie on this name, alter you cna add more data to it
    randomChump("Yusha");
    zombienew->announce();
    delete zombienew;
    return (0);
}
