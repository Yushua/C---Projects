/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/27 16:25:29 by ybakker       #+#    #+#                 */
/*   Updated: 2021/10/04 10:23:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//update index
void Phonebook::checking(Contacts contacts)
{
	if (amount_in_list > 7)
	{
		amount_in_list = 0;
		clear = 0;
		
	}
	if (amount_in_list == -1)
		amount_in_list = 0;
	_contacts[amount_in_list] = contacts;
	amount_in_list++;
	return ;
}

void Phonebook::check_index(int index)
{
	if (index < 0)
	{
		std::cout << "index is bigger than the available index list" << std::endl;
		return;
	}
	_contacts[index].all_contacts();
}

int Phonebook::search(void)
{
	int amount = 7;

	if (amount_in_list != -1)
	{
		std::cout << "     index|first name| last name|  nickname" << std::endl;
		int i = 0;
		if (clear == 0)
		{
			while (i < amount)
			{
				_contacts[i].format_print(i);
				i++;
			}
			return (amount);
		}
		else
		{
			while (i < amount_in_list && i < 8)
			{
				_contacts[i].format_print(i);
				i++;
			}
		}
	}
	return (amount_in_list);
}

void Contacts::check_field(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void Contacts::format_print(int index)
{
	std::cout << std::setw(10) << index << "|";
	this->check_field(_first_name);
	std::cout << "|";
	this->check_field(_last_name);
	std::cout << "|";
	this->check_field(_nickname);
	std::cout << std::endl;
}

void Contacts::all_contacts(void)
{
		std::cout << std::setw(15) <<"first_name " << _first_name << std::endl
		<< std::setw(15) << "last_name " << _last_name << std::endl
		<< std::setw(15) << "Nickname " << _nickname << std::endl
		<< std::setw(15) << "Darkest_secret " << _darkest_secret << std::endl;
}
