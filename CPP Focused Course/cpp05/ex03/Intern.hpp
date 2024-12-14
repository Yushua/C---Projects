/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 03:20:06 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/12 15:21:36 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();

		Form *makeForm(std::string name, std::string target);

        Form    *_list[3];
    class FormNotWorking : public std::exception
    {
        public:
            FormNotWorking();
            virtual const char *what() const throw();
            virtual ~FormNotWorking() throw();
    };

 
};


   static   std::string levels[] = {
        "shrubbery",
        "robotomy",
        "Presidential",
    };
#endif
