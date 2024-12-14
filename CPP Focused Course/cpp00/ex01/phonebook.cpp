/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/27 16:25:29 by ybakker       #+#    #+#                 */
/*   Updated: 2021/10/04 10:13:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "search.hpp"

Phonebook::Phonebook(void)
{
	amount_in_list = -1;
	clear	= -1;
}

Contacts	_add(void)
{
	Contacts contacts;
	std::string buffer;
	std::getline(std::cin, buffer);
	std::cout << "first name" << std::endl;
	buffer = contacts.get_input("First Name");
	contacts.setfirstname(buffer);
	std::cout << "last name" << std::endl;
	buffer = contacts.get_input("Last Name");
	contacts.setlastname(buffer);
	std::cout << "nick name" << std::endl;
	buffer = contacts.get_input("Nick Name");
	contacts.setnickname(buffer);
	std::cout << "darkest secret" << std::endl;
	std::getline(std::cin, buffer);
	contacts.setdarkestsecret(buffer);
	return (contacts);
}

static int _menu_wrong()
{
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (1);
	if (!input.compare("EXIT"))
		return (1);
	if (!input.compare("SEARCH"))
		return (2);
	if (!input.compare("ADD"))
		return (3);
	else
		return (4);
	return (0);
}

static int _menu()
{
	std::string input;
	std::cout << "\nWelcome to your phonebook!\nThe available entries are: " << std::endl;
	std::cout << " - ADD \n - SEARCH \n - EXIT \n" << std::endl;
	std::cout << "please input either one of the available inputs\n==>: ";
	std::cin >> input;
	if (std::cin.eof())
		return (1);
	if (!input.compare("EXIT"))
		return (1);
	if (!input.compare("SEARCH"))
		return (2);
	if (!input.compare("ADD"))
		return (3);
	else
		return (4);
	return (0);
}

static void	_exit(void)
{
	std::cout << "exiting program, have a great day" << std::endl;
    exit(0);
}

int		main(void)
{
	Phonebook phonebook;
	int input = 0;
	int index = 0;
	int x = 0;
	texture();
	while (10)
	{
		input = _menu();
		if (input == 1)
			_exit();
		else if (input == 2)//seach
		{
			x = 0;
			while (x == 0)
			{
				input = phonebook.search();
				if (input == -1)
				{
					std::cout << "!!there is nothing in here yet, return to menu!!" << std::endl;
					input = 0;
					break ;
				}
				std::cout << "which one of the indexes do you want to see" << std::endl;
				std::cin >> index;
				if (std::cin.good() && index >= 0 && index < input)
				{
					phonebook.check_index(index);
					input = 0;
					x = 1;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "incorrect input " << input << std::endl;
				}
			}
		}
		else if (input == 3)//add
		{
			Contacts info = _add();
			phonebook.checking(info);
			input = 0;
		}
		else if (input == 4)
		{
			std::cout << "I'm sorry, that input is unavailable, try another one\n==> : ";
			input = _menu_wrong();
		}
	}
	return (0);
}

Phonebook::~Phonebook(void)
{
}
