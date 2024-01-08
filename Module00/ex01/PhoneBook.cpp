/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:00 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/08 21:55:08 by ychen2           ###   ########.fr       */
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

void	PhoneBook::Search() {
	std::string	cmd;
	int			num;
	bool		is_digit;

	for (int i = 0; IsAvailable(i) && i < 8; i++) {
		SearchPrint(i);
	}
	std::cout << "Please input the index (from 0 to 7).\n";
	if (!(std::getline(std::cin, cmd))) {
		return;
	}
	if (IsInputEmpty(cmd))
		return;
	is_digit = 1;
	for (int i = 0; cmd[i]; i++) {
		if (!std::isdigit(cmd[i])) {
			is_digit = 0;
			break;
		}
	}
	if (!is_digit) {
		std::cout << "Please input only digits.\n";
		return;
	}
	std::istringstream(cmd) >> num;
	if (num > 7 || num < 0)
		std::cout << "Please input the index only from 0 to 7.\n";
	else if (IsAvailable(num))
		SearchPrintAll(num);
	else
		std::cout << "No contacts found.\n";
}