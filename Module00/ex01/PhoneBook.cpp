/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:00 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/08 14:58:28 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::NewContact() {
	if (this->next < 8) {
		if (this->contacts[this->next].InputInfo()) {
			std::cout << "Contacts["<< this->next << "] added.\n";
			this->next++;
		}
	}
	else {
		this->next = 0;
		PhoneBook::NewContact();
	}
}

void	PhoneBook::SearchPrint(int n) {
	std::cout << std::setw(10) << n << "|";
	this->contacts[n].PrintSimple();
}

void	PhoneBook::SearchPrintAll(int n) {
	this->contacts[n].PrintAll();
}

int		PhoneBook::IsAvailable(int n) {
	return (contacts[n].IsAvailable());
}

PhoneBook::PhoneBook() {
	this->next = 0;
}
