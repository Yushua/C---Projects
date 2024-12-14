/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 14:31:33 by ybakker       #+#    #+#                 */
/*   Updated: 2021/09/27 14:59:46 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void Zombie::announce(void)
{
    std::cout << YELLOW << _name << RESET << GREEN << " BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout << WHITE << "Hello, I`m " << RESET << YELLOW << _name << RESET << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << YELLOW << _name << RESET << " has " << RED << "died" << RESET << std::endl;
}
