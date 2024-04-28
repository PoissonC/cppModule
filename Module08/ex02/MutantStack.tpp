/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:45:38 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 23:12:44 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {
	std::cout << "Default constructor of MutantStack is called.\n";
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& cont) : std::stack<T, Container>(cont) {
	std::cout << "Copy constructor of MutantStack is called.\n";
}

template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container> & other) {
	std::cout << "Copy assignment operator of MutantStack is called.\n";
	if (this != &other) { 
		std::stack<T, Container>::operator=(other);
	}
	return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {
	std::cout << "Default destructor of MutantStack is called.\n";
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const {
	return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const {
	return this->c.end();
}