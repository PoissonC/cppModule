/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:09:22 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/08 15:27:42 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	IsInputEmpty(std::string in) {
	if (!in[0]) {
		std::cout << "ERROR: Input should not be empty.\n";
		return (1);
	}
	return (0);
}

static int	IsInputAvailable(std::string in) {
	if (IsInputEmpty(in))
		return (0);
	for (int i = 0; in[i]; i++) {
		if (!std::isalpha(in[i])) {
			std::cout << "ERROR: Input should contain only alphabets.\n";
			return (0);
		}
	}
	return (1);
}

int	Contact::InputInfo() {
	//
	std::cout << "Please input first name: ";
	if (!(std::getline(std::cin, first_name)))
		return (0);
	if (!IsInputAvailable(first_name)) {
		return (0);
	}
	//
	std::cout << "Please input last name: ";
	if (!(std::getline(std::cin, last_name)))
		return (0);
	if (!IsInputAvailable(last_name)) {
		return (0);
	}
	//
	std::cout << "Please input nickname: ";
	if (!(std::getline(std::cin, nickname)))
		return (0);
	if (!IsInputAvailable(nickname)) {
		return (0);
	}
	//
	std::cout << "Please input phone number: ";
	if (!(std::getline(std::cin, number)))
		return (0);
	if (IsInputEmpty(number))
		return (0);
	for (int i = 0; number[i]; i++) {
		if (!std::isdigit(number[i])) {
			std::cout << "ERROR: Phone Number contains not digits elements.\n";
			return (0);
		}
	}
	std::cout << "Please input darkest secret: ";
	if (!(std::getline(std::cin, darkest_secret)))
		return (0);
	if (IsInputEmpty(darkest_secret))
		return (0);
	available = 1;
	return (1);
}

static void	Print(std::string prt) {
	if (prt.length() > 10) {
		prt = prt.substr(0, 9);
		prt += ".";
	}
	std::cout << std::setw(10) << prt + "|";
}

void	Contact::PrintSimple() {
	Print(first_name);
	Print(last_name);
	Print(nickname);
	Print(number);
	std::cout << std::endl;
}

void	Contact::PrintAll() {
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nick name: " << nickname << std::endl;
	std::cout << "Phone number: " << number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

int		Contact::IsAvailable() {
	return (available);
}

Contact::Contact() {
	available = 0;
}