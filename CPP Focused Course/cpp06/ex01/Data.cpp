/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 16:07:38 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/12 21:38:33 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    // std::string* res = new std::string[sizeof(ptr->string)];//dosn't really matter what, just that it has the correct size
    // *reinterpret_cast<std::string*>(res) = ptr->string;
    return (reinterpret_cast<uintptr_t>(ptr));
}


Data* deserialize(uintptr_t raw)
{
    // Data* main = new Data;
    // std::string* ptr = reinterpret_cast<std::string*>(raw);
    // main->string = *reinterpret_cast<std::string*>(ptr);
    return (reinterpret_cast<Data*>(raw));
}