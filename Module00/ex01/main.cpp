/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:54:55 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/21 16:33:08 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
		if (std::strcmp("ADD", cmd.c_str()) == 0) {
			pb.NewContact();
		}
		else if (std::strcmp("SEARCH", cmd.c_str()) == 0) {
			scanf("%8d", &num);
			if (num > 7 || num < 0)
				printf("No contacts found.\n");
			else if (pb.IsAvailable(num)) {
				pb.PrintContact(num);
			}
			else
				printf("No contacts found.\n");
		}
		else if (std::strcmp("EXIT", cmd.c_str()) == 0) {
			break ;
		}
	}
}
