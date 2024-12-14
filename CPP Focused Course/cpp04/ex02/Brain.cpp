/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/03 19:03:22 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int	x;
    int i = 0;
    
	while (i < 100)
    {
        std::string names[] = {
            "codamn1",
            "codamn2",
            "codamn3",
            "codamn4",
            "codamn5",
            "codamn6"};
        x = rand() % 6;
		this->_ideas[i] = names[x];
        i++;
	}
}

Brain::Brain(const Brain& copy)
{
	int i = 0;

	while (i < 100)
	{
		this->_ideas[i] = copy._ideas[i];
		i++;
	}
}

Brain::~Brain()
{
	std::cout << "Brain is dead" << std::endl;
}

Brain&	Brain::operator=(const Brain &copy)
{
	int i = 0;

	while (i < 100)
	{
		this->_ideas[i] = copy._ideas[i];
		i++;
	}
	return (*this);
}
