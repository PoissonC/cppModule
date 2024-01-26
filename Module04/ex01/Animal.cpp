/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/26 18:01:34 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Non") {
	std::cout << "Default constructor of Animal called" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Copy constructor of Animal called" << std::endl;
	if (this != &other)
		type = other.type;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << "Copy assignment of Animal operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Destructor of Animal called" << std::endl;
}

std::string	Animal::getType( void ) const {
	return (type);
}

void	Animal::makeSound() const {
	std::cout << "Animal sound?" << std::endl;
}

const Brain*	Animal::whereIsMyBrain( void ) const {
	return NULL;
}
