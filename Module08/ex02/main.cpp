/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/04/28 15:59:11 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	std::cout << "MutantStack:\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;	
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	// the following line is the reason that we use deque as the default container choice of iterator
	std::stack<int> s(mstack);
	// or use this instead
	// std::stack<int, std::vector<int> > s(mstack);

	std::cout << "List:\n";
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << *lst.rbegin() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator it_lst = lst.begin();
	std::list<int>::iterator ite_lst = lst.end();
	++it_lst;
	--it_lst;	
	while (it_lst != ite_lst)
	{
		std::cout << *it_lst << " ";
		++it_lst;
	}
	std::cout << std::endl;


	// for OCF tests
	std::cout << "OCF tests:\n";
	std::cout << "Copy constructor tests:\n";
	MutantStack<int> copy_mstack(mstack);
	for (MutantStack<int>::iterator it = copy_mstack.begin(); it != copy_mstack.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\nCopy assignment tests:\n";
	MutantStack<int> copy2_mstack;
	copy2_mstack = mstack;
	for (MutantStack<int>::iterator it = copy2_mstack.begin(); it != copy2_mstack.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
