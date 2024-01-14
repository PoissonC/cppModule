/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:44:47 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default constructor of Brain called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Copy constructor of Brain called" << std::endl;
	*this = other;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Copy assignment of Brain operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Destructor of Brain called" << std::endl;
}

std::string	Brain::getIdea(int i) const {
	return (ideas[i]);
}

void	Brain::setIdea(std::string newIdea, int i) {
	ideas[i] = newIdea;
}
