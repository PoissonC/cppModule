/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/02/28 22:08:38 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "Default constructor of MateriaSource called" << std::endl;
	this->_sused = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	// std::cout << "Copy constructor of MateriaSource called" << std::endl;
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	// std::cout << "Copy assignment of MateriaSource operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < other._sused; i++) {
			this->_slots[i] = other._slots[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	// std::cout << "Destructor of MateriaSource called" << std::endl;
	for (int i = 0; i < this->_sused; i++) {
			delete this->_slots[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (this->_sused < 4) {
		this->_slots[this->_sused] = m;
		this->_sused += 1;
	}
	else {
		std::cout << "No slot available in this MateriaSource." << std::endl;
		delete m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_sused; i++) {
		if (this->_slots[i]->getType() == type) {
			return this->_slots[i]->clone();
		}
	}
	std::cout << "Materia not found." << std::endl;
	return (NULL);
}