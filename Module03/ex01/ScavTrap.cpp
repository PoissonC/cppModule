/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 21:09:44 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructor & destructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "\033[34mDefault constructor of ScavTrap called\033[0m" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	// std::cout << "Hp: " << this->_hitPoints << std::endl;
	// std::cout << "Ep: " << this->_energyPoints << std::endl;
	// std::cout << "Ad: " << this->_attackDamage << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	std::cout << "\033[34mCopy constructor of ScavTrap called\033[0m" << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "\033[34mCopy assignment operator of ScavTrap called\033[0m" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "\033[34mDestructor of ScavTrap called\033[0m" << std::endl;
}

// member functions

void	ScavTrap::guardGate(void) {
	if (this->_hitPoints == 0) {
		std::cout << "\033[34mScavTrap " << this->_name << " is already broken, can't enter Gate keeper mode.\n\033[0m";
		return ;
	}
	std::cout << "\033[34mScavTrap " << this->_name << " has enterred in Gate keeper mode.\n\033[0m";
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "\033[34mScavTrap " << this->_name << " is already broken.\n\033[0m";
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "\033[34mScavTrap " << this->_name << " has no energy to attack.\n\033[0m";
		return ;
	}
	std::cout << "\033[34mScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " remains " << this->_energyPoints << "  EP.\n\033[0m";
}
