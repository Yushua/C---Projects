/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/04 18:08:47 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/07 17:04:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _N(N)
{
    this->_N = N;
    this->_vector.reserve(N);   
}

Span::Span(const Span& copy)
{
    *this = copy;
}

Span::~Span()
{
    this->_vector.clear();
}

Span&	Span::operator=(const Span &copy)
{
	this->_N = copy._N;
    this->_vector = copy._vector;
	return (*this);
}

void Span::addNumber(int nb)
{
    if (this->_vector.size() == this->_N)
        throw(std::runtime_error("not found"));
    else
        this->_vector.push_back(nb);
}

int Span::shortestSpan(void)
{
    if (this->_vector.size() < 2)
        throw(std::runtime_error("not enough input in vector"));
    std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());

	std::vector<int>::const_iterator begin = tmp.begin();
	std::vector<int>::const_iterator end = tmp.end();
	std::vector<int>::const_iterator x = begin;

	int min = *(begin + 1) - *begin;
	for (int number = 0; x + 1 != end; x++)
	{
		number = *(x + 1) - *x;
		if (number < min)
			min = number;
	}

	return(min);
}

int Span::longestSpan(void)
{
    if (this->_vector.size() < 2)
        throw(std::runtime_error("not enough input in vector"));
    //so the first and last
    std::vector<int>tmp = this->_vector;
    sort(tmp.begin(), tmp.end());
    int i = 0;
    i = tmp.back() - tmp.front();
    return (i);
} 
