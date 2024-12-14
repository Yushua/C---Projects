/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/27 16:11:03 by ybakker       #+#    #+#                 */
/*   Updated: 2021/10/04 10:13:00 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <stdlib.h>
# include <iomanip>

class Contacts
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _darkest_secret;
	public:
	//input the information
		std::string get_input(std::string message);
		void setfirstname(std::string);
		void setlastname(std::string);
		void setnickname(std::string);
		void setdarkestsecret(std::string);
	//functions
		void all_contacts(void);
		void format_print(int index);
		void check_field(std::string str);
};

class Phonebook
{
	public:
		Phonebook();
			void 	checking(Contacts contacts);
			// SEARCH
			int     search(void);
			void 	check_index(int index);
		~Phonebook();
	private:
		Contacts _contacts[8];
		int	amount_in_list;
		int	clear;
};

// TEXTURES
void	texture(void);

//saved

#endif
