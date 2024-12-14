/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 20:14:52 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/12 18:33:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
    Data* main = new Data;
    
    main->string = "hello";
    
    std::cout << "start             :" << main->string << std::endl;
    uintptr_t raw = serialize(main);
    std::cout << "serialized        :" << raw << std::endl;
    Data* neww = deserialize(raw);
    std::cout << "main deserialized :" << neww->string << std::endl;
    std::cout << "neww deserialized :" << main->string << std::endl;
    return 0;
}