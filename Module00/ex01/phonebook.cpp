/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:00 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/21 13:37:07 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

char*	PhoneBook::getPhoneNumber(int n) {
	if (n >= 8)
		return (NULL);
	return (this->contacts[n].getNumber());
}

char*	PhoneBook::getPhoneName(int n) {
	if (n >= 8)
		return (NULL);
	return (this->contacts[n].getName());
}


void	PhoneBook::newContact() {
	if (this->next < 8) {
		if (this->contacts[this->next].getName() || this->contacts[this->next].getNumber())
			this->contacts[this->next].deleteOne();
		this->contacts[this->next].inputName();
		if (this->contacts[this->next].getName()) {
			this->contacts[this->next].inputNumber();
			this->next++;
		}
	}
	else {
		next = 0;
		PhoneBook::newContact();
	}
}

PhoneBook::PhoneBook() {
	this->next = 0;
}
