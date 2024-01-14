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
	_brain = new Brain;
	Animal::type = "Dog";
}

Dog::Dog(const Dog& other) {
	std::cout << "Copy constructor of Dog called" << std::endl;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Copy assignment of Dog operator called" << std::endl;
	_brain = new Brain;
	if (this != &other)
		Animal::type = other.type;
	for (int i = 0; i < 100; i++)
		_brain->setIdea(other._brain->getIdea(i), i);
	return *this;
}

Dog::~Dog() {
	std::cout << "Destructor of Dog called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << "Owf owf!!" << std::endl;
}

const Brain*	Dog::whereIsMyBrain( void ) const {
	return (_brain);
}
