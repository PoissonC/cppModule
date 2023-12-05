/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:54:55 by ychen2            #+#    #+#             */
/*   Updated: 2023/12/04 22:02:35 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook	pb;
	std::string	cmd;
	int			num;

	while (1) {
		if (std::cin.eof())
			break ;
		std::cout << "Please input the command (ADD, SEARCH, EXIT):\n";
		if (!(std::cin >> cmd)) {
			break ;
		}
		if (cmd == "ADD") {
			pb.NewContact();
		}
		else if (cmd == "SEARCH") {
			std::cin >> num;
			std::cin.clear();
			if (num > 7 || num < 0)
				std::cout << "No contacts found.\n";
			else if (pb.IsAvailable(num)) {
				pb.PrintContact(num);
			}
			else
				std::cout << "No contacts found.\n";
		}
		else if (cmd == "EXIT") {
			break ;
		}
	}
}
