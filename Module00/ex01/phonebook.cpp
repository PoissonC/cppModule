/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:00 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/21 16:11:49 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
	std::cout << std::setw(10) << std::to_string(n) + "|";
	this->contacts[n].Print();
}

int		PhoneBook::IsAvailable(int n) {
	return (contacts[n].IsAvailable());
}

PhoneBook::PhoneBook() {
	this->next = 0;
}
