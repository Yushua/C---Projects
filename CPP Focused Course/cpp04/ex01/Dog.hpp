/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/16 22:27:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(Dog& Dog);
		virtual ~Dog();
		Dog& operator=(const Dog& copy);

		virtual void makeSound() const;
		std::string* getIdeas();
		Brain *getBrain() const;
};

#endif