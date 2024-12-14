/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 14:35:48 by ybakker       #+#    #+#                 */
/*   Updated: 2022/09/08 17:19:04 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>

int main()
{
	MutantStack<int> _Mutant;
	//add some numbers, and the last number you added should pop up
	_Mutant.push(1);
	_Mutant.push(10);
	_Mutant.push(34);
	_Mutant.push(42);
	std::cout << "remove the top, so the number we just saw" << std::endl;
	std::cout << "[" << _Mutant.top() << "]" << std::endl;
	_Mutant.pop();
	std::cout << "so using pop again should give us the second last number" << std::endl;
	std::cout << "[" << _Mutant.top() << "]" << std::endl;
	std::cout << "the size" << std::endl;
	std::cout << "[" << _Mutant.size() << "]" << std::endl;
	
	std::cout << "\n======== List ========" << std::endl;
	std::list<int> list;
	//add some numbers, and the last number you added should pop up
	list.push_back(1);
	list.push_back(10);
	list.push_back(34);
	list.push_back(42);
	std::cout << "[" << list.back() << "]" << std::endl;
	list.pop_back();//remove the back, so the number we just saw
	//so using pop again should give us the second last number
	std::cout << "[" << list.back() << "]" << std::endl;
	//how many push_backes you gave it
	std::cout << "[" << list.size() << "]" << std::endl;
	
	std::cout << "\n======== Special ========" << std::endl;
	std::stack<int> _special(_Mutant);
	//add some numbers, and the last number you added should pop up
	_special.push(1);
	_special.push(10);
	_special.push(34);
	_special.push(42);
	std::cout << "[" << _special.top() << "]" << std::endl;
	_special.pop();
	std::cout << "[" << _special.top() << "]" << std::endl;
	std::cout << "[" << _special.size() << "]" << std::endl;

	std::cout << "\n======== iterator ========" << std::endl;
	std::cout << "input from the list" << std::endl;
	MutantStack<int>::iterator _b_iterator = _Mutant.begin();
	MutantStack<int>::iterator _e_iterator = _Mutant.end();
	while (_b_iterator < _e_iterator)
	{
		std::cout << "[" << *_b_iterator << "]" << std::endl;
		++_b_iterator;
	}
	std::cout << "\n======== reverse_iterator ========" << std::endl;
	std::cout << "input from the list but reversed position" << std::endl;
	MutantStack<int>::reverse_iterator r_b_iterator = _Mutant.rbegin();
	MutantStack<int>::reverse_iterator r_e_iterator = _Mutant.rend();
	while (r_b_iterator < r_e_iterator)
	{
		std::cout << "[" << *r_b_iterator << "]" << std::endl;
		++r_b_iterator;
	}
	return 0;
}
