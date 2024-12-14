/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 19:40:55 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/15 22:19:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon* _arm;//not always armed
        std::string _name;

    public:
        HumanB(std::string);
        ~HumanB();
        void attack();
        void setWeapon(Weapon&);
};

#endif
