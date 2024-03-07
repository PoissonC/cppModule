/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:45:38 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 23:12:44 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _number(N) {
}


Span::Span(const Span & other) : _number(other._number), _vec(other._vec){
}

Span&	Span::operator=(const Span & other) {
	if (this != &other) {
		this->_number = other._number;
		this->_vec = other._vec;
	}
	return *this;
}

Span::~Span() {
}

void	Span::addNumber(int new_num) {
	if (this->_vec.size() < this->_number) {
		this->_vec.push_back(new_num);
	}
	else
		throw AlreadyFull();
}

int	Span::shortestSpan() {
	int	shortest;

	if (this->_vec.size() <= 1)
		throw NoSpanFound();
	std::sort(this->_vec.begin(), this->_vec.end());
	shortest = this->_vec[this->_vec.size() - 1] - this->_vec[0];
	for (unsigned long i = 0; i < this->_vec.size() - 1; i++) {
		if (this->_vec[i + 1] - this->_vec[i] < shortest)
			shortest = this->_vec[i + 1] - this->_vec[i];
	}
	return shortest;
}

int	Span::longestSpan() {
	if (this->_vec.size() <= 1)
		throw NoSpanFound();
	std::sort(this->_vec.begin(), this->_vec.end());
	return (this->_vec[this->_vec.size() - 1] - this->_vec[0]);
}
const char*	Span::AlreadyFull::what() const throw() {
	return "No space left to add more elements.";
}

const char*	Span::NoSpanFound::what() const throw() {
	return "No span found.";
}
