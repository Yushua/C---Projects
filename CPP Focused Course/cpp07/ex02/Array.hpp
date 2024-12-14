/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 21:47:37 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/06 16:13:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <cstdlib>

template<typename T>
class Array
{
    class InvalidIndex : public std::exception
    {
        public:
            virtual const char* what()const throw();
    };
    private:
        T* _array;
        unsigned int _n;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        ~Array();
        Array& operator=(const Array& copy);
        T&	operator[](unsigned int index);
        unsigned int	size();
};


template <typename T>    
Array<T>::Array()
{
    this->_array = new T[0];
}

template <typename T>    
Array<T>::Array(unsigned int n)
{
    this->_array = new T[n];
    for (unsigned int i = 0; i < n; i++)
        this->_array[i] = 0;
    this->_n = n;
}

template <typename T>    
Array<T>::Array(const Array& copy)
{
    this->_n = copy._n;
    this->_array = new T [this->_n];//making a new array
    for (unsigned int i = 0; i < this->_n; i++)
        this->_array[i] = copy._array[i];
}

template <typename T>    
Array<T>::~Array()
{
    if(this->_array)
        delete[] _array;//delete all the arrays in one time
    return;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& copy)
{
    this->_array = new T[this->_n];
    for (unsigned int i = 0; i < copy.size(); i++)
        this->_array[i] = copy._array[i];
    this->_n = copy._n;
    return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= this->_n)
		throw InvalidIndex();
	return (this->_array[index]);
}

template <typename T>
unsigned int	Array<T>::size()
{
	return (this->_n);
}

template <typename T>
const char*	Array<T>::InvalidIndex::what() const throw()
{
	return "Invalid index";
}

#endif
