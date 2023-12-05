/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:09:22 by ychen2            #+#    #+#             */
/*   Updated: 2023/12/04 20:48:38 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	Contact::InputInfo(){
	std::cout << "Please input first name: ";
	if (!(std::cin >> first_name))
		return (0);
	if (first_name.length() > 10) {
		first_name = first_name.substr(0, 9);
		first_name += ".";
	}
	std::cout << "Please input last name: ";
	if (!(std::cin >> last_name))
		return (0);
	if (last_name.length() > 10) {
		last_name = last_name.substr(0, 9);
		last_name += ".";
	}
	std::cout << "Please input nickname: ";
	if (!(std::cin >> nickname))
		return (0);
	if (nickname.length() > 10) {
		nickname = nickname.substr(0, 9);
		nickname += ".";
	}
	std::cout << "Please input phone number: ";
	if (!(std::cin >> number))
		return (0);
    for (int i = 0; number[i]; i++) {
        if (!std::isdigit(number[i])) {
			std::cout << "ERROR: Phone Number contains not digits elements.\n";
			return (1);
        }
    }
	if (number.length() > 10) {
		number = number.substr(0, 9);
		number += ".";
	}
	std::cout << "Please input darkest secret: ";
	if (!(std::cin >> darkest_secret))
		return (0);
	available = 1;
	return (0);
}

void	Contact::Print() {
	std::cout << std::setw(10) << first_name + "|";
	std::cout << std::setw(10) << last_name + "|";
	std::cout << std::setw(10) << nickname + "|";
	std::cout << std::setw(10) << number << std::endl;
}

int		Contact::IsAvailable() {
	return (available);
}

Contact::Contact() {
	available = 0;
}