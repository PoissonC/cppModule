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

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const Container& cont) : std::stack<T, Container>(cont) {
}

template<typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template<typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end() {
	return this->c.end();
}

template<typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const {
	return this->c.begin();
}

template<typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::end() const {
	return this->c.end();
}