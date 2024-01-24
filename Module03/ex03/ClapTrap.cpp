/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 20:34:30 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// constructor & destructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor of ClapTrap called" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator of ClapTrap called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor of ClapTrap called" << std::endl;
}

// member functions
void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "\033[31mClapTrap " << this->_name << " is already broken.\n\033[0m";

		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "\033[31mClapTrap " << this->_name << " has no energy to attack.\n\033[30m";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " remains " << this->_energyPoints << "  EP.\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "\033[31mDon't do this! ClapTrap " << this->_name << " is already broken.\n\033[0m";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is attacked, causing " << amount << " points of damage!\n";
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	if (this->_hitPoints == 0)
		std::cout << "\033[31mClapTrap " << this->_name << " is broken.\n\033[0m";
	else
		std::cout << "ClapTrap " << this->_name << " remains " << this->_hitPoints << "  HP.\n";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints >= 1000) {
		std::cout << "\033[32mClapTrap " << this->_name << "'s Hp has reached the maximum.\n\033[0m";
		return ;
	}
	if (this->_hitPoints == 0) {
		std::cout << "\033[31mClapTrap " << this->_name << " is already broken.\n\033[0m";
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "\033[31mClapTrap " << this->_name << " has no energy to be repaired.\n\033[0m";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is repaired, restore " << amount << " points of HP!\n";
	this->_hitPoints += amount;
	if (this->_hitPoints >= 1000)
		this->_hitPoints = 1000;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " remains " << this->_hitPoints << "  HP.\n";
	std::cout << "ClapTrap " << this->_name << " remains " << this->_energyPoints << "  EP.\n";
}
