/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/04 18:08:56 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/04 18:41:03 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H
#include <string>
#include <iostream>
#include <cstdlib>
# include <vector>
# include <limits>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _vector;
    public:
        Span(unsigned int N);
        Span(const Span& copy);
        ~Span();
        Span& operator=(const Span& copy);
        
        void addNumber(int nb);
        int shortestSpan(void);
        int longestSpan(void);
};
# endif
