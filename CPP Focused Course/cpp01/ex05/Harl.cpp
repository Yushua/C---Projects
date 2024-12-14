/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 14:28:54 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/15 22:09:02 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void Harl::debug()
{
    std::cout << GREEN << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << RESET << std::endl;
}

void Harl::info()
{
    std::cout <<  BLUE << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n" << RESET << std::endl;
}

void Harl::warning()
{
    std::cout <<  MAGENTA << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n"<< RESET << std::endl;
}

void Harl::error()
{
    std::cout <<  RED << "This is unacceptable, I want to speak to the manager now.\n" << RESET << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*ptrs[]) (void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    void (Harl::*complain)(void);
    for (int i = 0; i < 4; i++)
    {
        complain = ptrs[i];
        if (levels[i] == level)
            (this->*complain)();
    }
    
}
