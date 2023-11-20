/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:54:55 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/20 18:26:48 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main() {
	char	cmd[7];

	while (1) {
		scanf("%7s", cmd);
		if (strcmp("ADD", cmd) == 0) {

		}
		else if (strcmp("SEARCH", cmd) == 0) {
			
		}
		else if (strcmp("EXIT", cmd) == 0) {
			break ;
		}
	}
}
