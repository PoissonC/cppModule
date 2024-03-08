/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:19:01 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/08 11:54:48 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name) {
	// std::cout << "Default constructor of Character called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_iused[i] = false;
}

Character::Character(const Character& other) {
	// std::cout << "Copy constructor of Character called" << std::endl;
	*this = other;
}

Character&	Character::operator=(const Character& other) {
	// std::cout << "Copy assignment of Character operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (other._iused[i]) {
				this->_inventory[i] = other._inventory[i]->clone();
				this->_iused[i] = true;
			}
			else
				this->_iused[i] = false;
		}
	}
	return *this;
}

Character::~Character() {
	// std::cout << "Destructor of Character called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_iused[i])
			delete this->_inventory[i];
	}
}

std::string	const & Character::getName() const {
	return (this->_name);
}
AMateria* Character::getInventory(const int & index) const {
	if (this->_iused[index])
		return this->_inventory[index];
	else
		return NULL;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_iused[i] == false) {
			this->_inventory[i] = m;
			this->_iused[i] = true;
			return ;
		}
	}
	std::cout << "The inventory of " << this->_name << " is full." << std::endl;
	delete m;
}
void	Character::unequip(int idx) {
	if (this->_iused[idx]) {
		this->_iused[idx] = false;
	}
	else
		std::cout << "The idx " << idx << " of " << this->_name << " is empty, can't be unequiped" << std::endl;
}
void	Character::use(int idx, ICharacter& target) {
	if (this->_iused[idx]) {
		this->_inventory[idx]->use(target);
		delete this->_inventory[idx];
		this->_iused[idx] = false;
	}
	else
		std::cout << "The idx " << idx << " of " << this->_name << " is empty, can't be used." << std::endl;
}
