/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:04:30 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Default constructor of Dog called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) {
	std::cout << "Copy constructor of Dog called" << std::endl;
	*this = other;
}

static void	swap(Dog &a, Dog &b) {
	Dog	tmp = a;
	a = b;
	b = tmp;
}

Dog&	Dog::operator=(Dog other) {
	std::cout << "Copy assignment of Dog operator called" << std::endl;

	this->type = other.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Destructor of Dog called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Owf owf!!" << std::endl;
}
