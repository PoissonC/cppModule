/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:24:14 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/12 01:58:05 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	// ScalarConverter test;
	if (ac != 2) {
		std::cout << "Wrong number of input arguments." << std::endl;
		return (1);
	}
	std::string	tmp = av[1];
	if (ScalarConverter::convert(tmp))
		return (1);
	return (0);
}