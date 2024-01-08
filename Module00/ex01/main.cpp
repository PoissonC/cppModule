/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:54:55 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/08 15:28:22 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook	pb;
	std::string	cmd;
	int			num;
	bool		is_digit;

	while (1) {
		if (std::cin.eof())
			break ;
		std::cout << "Please input the command (ADD, SEARCH, EXIT):\n";
		if (!(std::getline(std::cin, cmd))) {
			break ;
		}
		if (cmd == "ADD") {
			pb.NewContact();
		}
		else if (cmd == "SEARCH") {
			for (int i = 0; pb.IsAvailable(i); i++) {
				pb.SearchPrint(i);
			}
			std::cout << "Please input the index (from 0 to 7).\n";
			if (!(std::getline(std::cin, cmd))) {
				continue;
			}
			if (IsInputEmpty(cmd))
				continue;
			is_digit = 1;
			for (int i = 0; cmd[i]; i++) {
				if (!std::isdigit(cmd[i])) {
					is_digit = 0;
					break;
				}
			}
			if (!is_digit) {
				std::cout << "Please input only digits.\n";
				continue;
			}
			num = std::stoi(cmd);
			if (num > 7 || num < 0)
				std::cout << "Please input the index only from 0 to 7.\n";
			else if (pb.IsAvailable(num)) {
				pb.SearchPrintAll(num);
			}
			else
			{
				std::cout << "No contacts found.\n";
			}
		}
		else if (cmd == "EXIT") {
			break ;
		}
	}
	return (0);
}
