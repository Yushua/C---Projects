/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 03:22:47 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/16 19:43:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern& copy)
{
	*this = copy;
}

Intern::~Intern()
{
    
}

Intern&	Intern::operator=(const Intern& copy)
{
    if (this != &copy)
	{
	    (void)copy;
	}
	return *this;
}

Form	*Intern::makeForm(std::string name, std::string target)
{
    Form    *new_form = 0;

    try
    {
        _list[0] = new ShrubberyCreationForm(target);
        _list[1] = new RobotomyRequestForm(target);
        _list[2] = new PresidentialPardonForm(target);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        for (int y = 0; y < 3; y++)
            delete _list[y];
        throw Intern::FormNotWorking();
    }
    //check if thees fail
    std::string levels[] = {
        "shrubbery",
        "robotomy",
        "Presidential",
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (levels[i] == name)
		{
            new_form = _list[i]->clone();
            // delete _list[];
            for (int y = 0; y < 3; y++)
                delete _list[y];
			std::cout << "intern creates " << levels[i] << "." << std::endl;
            return((new_form));
		}
    }
    for (int y = 0; y < 3; y++)
        delete _list[y];
	throw Intern::FormNotWorking();
}

Intern::FormNotWorking::FormNotWorking()
{
}

const char *Intern::FormNotWorking::what() const throw()
{
	return "form not working";
}

Intern::FormNotWorking::~FormNotWorking() throw()
{
}
