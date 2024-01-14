/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 21:25:21 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Default constructor of Cat called" << std::endl;
	Animal::type = "Cat";
	_brain = new Brain;
}

Cat::Cat(const Cat& other) {
	std::cout << "Copy constructor of Cat called" << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Copy assignment of Cat operator called" << std::endl;
	_brain = new Brain;
	if (this != &other)
		Animal::type = other.type;
	for (int i = 0; i < 100; i++)
		_brain->setIdea(other._brain->getIdea(i), i);
	return *this;
}

Cat::~Cat() {
	std::cout << "Destructor of Cat called" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const {
	std::cout << "meow meow~" << std::endl;
}

const Brain*	Cat::whereIsMyBrain( void ) const {
	return (_brain);
}
