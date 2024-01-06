/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/06 20:49:54 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// constructor & destructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Default constructor of FragTrap called" << std::endl;
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << "Copy constructor of FragTrap called" << std::endl;
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << "Copy assignment operator of FragTrap called" << std::endl;
	if (this != &other) {
		this->setName(other.getName());
		this->setHp(other.getHp());
		this->setEp(other.getEp());
		this->setAd(other.getAd());
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor of FragTrap called" << std::endl;
}

// member functions
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->getName() << " is asking for high fives.\n";
}

void	FragTrap::attack(const std::string& target) {
	if (this->getHp() == 0) {
		std::cout << "FragTrap " << this->getName() << " is already broken.\n";
		return ;
	}
	if (this->getEp() == 0) {
		std::cout << "FragTrap " << this->getName() << " has no energy to attack.\n";
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAd() << " points of damage!\n";
	this->setEp(this->getEp() - 1);
	std::cout << "FragTrap " << this->getName() << " remains " << this->getEp() << "  EP.\n";
}
