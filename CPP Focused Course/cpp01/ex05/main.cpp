/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 14:28:47 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/15 22:49:45 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "DEBUG: " ; harl.complain("DEBUG");
	std::cout << "INFO: " ; harl.complain("INFO");
	std::cout << "WARNING: " ; harl.complain("WARNING");
	std::cout << "ERROR: " ; harl.complain("ERROR");
    return (0);
}
