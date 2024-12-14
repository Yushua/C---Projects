/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 00:44:11 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/26 19:59:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap(std::string name);
        ~ScavTrap();

        //original attack message
        ScavTrap& operator=(const ScavTrap &other);
        void attack(std::string const & target);
        void guardGate();
};

#endif
