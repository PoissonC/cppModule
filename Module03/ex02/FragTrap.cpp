/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 21:04:57 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// constructor & destructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Default constructor of FragTrap called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << "Copy constructor of FragTrap called" << std::endl;
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << "Copy assignment operator of FragTrap called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor of FragTrap called" << std::endl;
}

// member functions

void	FragTrap::highFivesGuys(void) {
	if (this->_hitPoints == 0) {
		std::cout << "\033[33mFragTrap " << this->_name << " is already broken, can't ask for a high fives.\n\033[0m";
		return ;
	}
	std::cout << "\033[33mFragTrap " << this->_name << " is asking for a high fives.\n\033[0m";
}

void	FragTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "\033[33mFragTrap " << this->_name << " is already broken.\n\033[0m";
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "\033[33mFragTrap " << this->_name << " has no energy to attack.\n\033[0m";
		return ;
	}
	std::cout << "\033[33mFragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
	std::cout << "FragTrap " << this->_name << " remains " << this->_energyPoints << "  EP.\n\033[0m";
}
