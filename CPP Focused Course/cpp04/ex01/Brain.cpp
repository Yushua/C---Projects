/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/03 19:02:42 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is born" << std::endl;
	int	x;
    int i = 0;
    
	while (i < 100)
    {
        std::string names[] = {
            "codam1",
            "codam2",
            "codam3",
            "codam4",
            "codam5",
            "codam6"};
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

Brain::~Brain()
{
	std::cout << "Brain is dead" << std::endl;
}

std::string const &Brain::getIdeas(int index)
{
	return(this->_ideas[index]);
}
