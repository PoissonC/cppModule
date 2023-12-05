/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:00 by ychen2            #+#    #+#             */
/*   Updated: 2023/12/04 20:48:48 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::NewContact() {
	if (this->next < 8) {
		if (this->contacts[this->next].InputInfo()) {
			this->next++;
		}
	}
	else {
		next = 0;
		PhoneBook::NewContact();
	}
}

void	PhoneBook::PrintContact(int n) {
	std::cout << std::setw(10) << n << "|";
	this->contacts[n].Print();
}

int		PhoneBook::IsAvailable(int n) {
	return (contacts[n].IsAvailable());
}

PhoneBook::PhoneBook() {
	this->next = 0;
}
