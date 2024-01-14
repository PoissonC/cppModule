/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:22:42 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Default constructor of Cat called" << std::endl;
	Animal::type = "Cat";
}

Cat::Cat(const Cat& other) {
	std::cout << "Copy constructor of Cat called" << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Copy assignment of Cat operator called" << std::endl;
	Animal::type = other.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Destructor of Cat called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "meow meow~" << std::endl;
}