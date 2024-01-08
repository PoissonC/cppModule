/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:54:55 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/08 20:10:32 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook	pb;
	std::string	cmd;

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
			pb.Search();
		}
		else if (cmd == "EXIT") {
			break ;
		}
	}
	return (0);
}
