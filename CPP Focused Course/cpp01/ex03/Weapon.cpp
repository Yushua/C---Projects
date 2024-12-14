/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 19:40:13 by ybakker       #+#    #+#                 */
/*   Updated: 2021/09/28 19:43:48 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type)
{
    this->_type = type;
    return;
}

Weapon::~Weapon()
{
    return;
}

void    Weapon::setType( std::string type )
{
    this->_type = type;
    return;
}

std::string& Weapon::getType()
{
    return (this->_type); 
}
