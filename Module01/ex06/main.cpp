/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:11 by yu                #+#    #+#             */
/*   Updated: 2024/01/12 12:52:04 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
    Harl harl;

	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments." << std::endl;
		return 1;
	}
	std::string level = av[1];
    harl.complain(level);
    return 0;
}