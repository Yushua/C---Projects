/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 00:44:11 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/30 17:47:21 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const ScavTrap& copy);
        ScavTrap(std::string name);
        ~ScavTrap();

        ScavTrap& operator=(const ScavTrap& other);
        virtual void attack(std::string const & target);
        void guardGate();
};

#endif
