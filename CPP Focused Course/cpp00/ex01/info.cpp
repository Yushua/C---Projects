/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2021/09/24 13:42:09 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//put information in

std::string Contacts::get_input(std::string message)
{
    std::string str;
	while (str.compare("") == 0)
	{
		std::getline(std::cin, str);
		if (str.compare("") == 0)
			std::cout << "Warning! "<< message << " cannot be empty!\n> ";
	}
	return (str);
}

void  Contacts::setfirstname(std::string s)
{
    this->_first_name = s;
}

void     Contacts::setlastname(std::string s)
{
    this->_last_name = s;
}

void     Contacts::setnickname(std::string s)
{
    this->_nickname = s;
}

void     Contacts::setdarkestsecret(std::string s)
{
    this->_darkest_secret = s;
}
