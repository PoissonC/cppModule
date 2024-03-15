/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/15 20:08:25 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <exception>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Wrong number of argument." << std::endl;
		return 1;	
	}

	try {
		input_check(av + 1)
		merge_insertion_sort_vector(av + 1);
		merge_insertion_sort_deque(av + 1);
	}
	catch (std::exception &e) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}
