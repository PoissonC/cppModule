/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 21:13:04 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// constructor & destructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "\033[35mDefault constructor of DiamondTrap called\033[0m" << std::endl;
	this->_energyPoints = 50;
	// std::cout << "Name of ClapTrap: " << ClapTrap::_name << std::endl;
	// std::cout << "Name of FragTrap: " << FragTrap::_name << std::endl;
	// std::cout << "Name of ScavTrap: " << ScavTrap::_name << std::endl;
	// std::cout << "Hp: " << this->_hitPoints << std::endl;
	// std::cout << "Ep: " << this->_energyPoints << std::endl;
	// std::cout << "Ad: " << this->_attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "\033[35mCopy constructor of DiamondTrap called\033[0m" << std::endl;
	*this = other;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "\033[35mCopy assignment operator of DiamondTrap called\033[0m" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		ClapTrap::_name = other._name + "_clap_name";
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "\033[35mDestructor of DiamondTrap called\033[0m" << std::endl;
}

// member functions
void	DiamondTrap::takeDamage(unsigned int amount) {
	ScavTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	ScavTrap::beRepaired(amount);
}

void	DiamondTrap::whoAmI() {
	std::cout << "\033[35mI am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << "\033[0m" << std::endl;
}