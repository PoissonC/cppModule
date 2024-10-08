/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:32:34 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 23:04:02 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
// #include <vector> for tests

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	typedef typename Container::iterator		iterator;
	typedef typename Container::const_iterator	const_iterator;

	// OCF
	MutantStack();
	MutantStack(const MutantStack& cont);
	MutantStack<T, Container>&	operator=(const MutantStack<T, Container> & other);
	~MutantStack();


	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

#include "MutantStack.tpp"