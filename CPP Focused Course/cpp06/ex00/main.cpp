/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 05:36:57 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/12 21:15:41 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
    {
		std::cout << "Argument Error\n" << std::endl;
		return 0;
	}
	Convert convert(argv[1]);
	convert.conversions();
	return 0;
}
