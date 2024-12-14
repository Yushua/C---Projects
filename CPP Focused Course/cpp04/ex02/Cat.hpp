/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/16 22:27:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(Cat& Cat);
		virtual ~Cat();
		Cat& operator=(const Cat& copy);

		virtual void makeSound() const;
		std::string* getIdeas();
		Brain *getBrain() const;
};

#endif