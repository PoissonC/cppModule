/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/06 02:23:47 by yu               ###   ########.fr       */
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