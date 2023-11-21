/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:54:55 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/21 13:43:39 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main() {
	PhoneBook	pb;
	char		cmd[7];
	int			num;

	while (1) {
		printf("Please input the command (ADD, SEARCH, EXIT):\n");
		if (scanf("%7s", cmd) <= 0)
			break ;
		getchar();
		if (strcmp("ADD", cmd) == 0) {
			pb.newContact();
		}
		else if (strcmp("SEARCH", cmd) == 0) {
			scanf("%9d", &num);
			num--;
			if (num >= 8 || num < 0)
				printf("No contacts found.\n");
			else if (pb.getPhoneName(num)) {
				printf("%s: %s", pb.getPhoneName(num), pb.getPhoneNumber(num));
			}
			else
				printf("No contacts found.\n");
		}
		else if (strcmp("EXIT", cmd) == 0) {
			break ;
		}
	}
}
