/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/21 22:01:17 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <exception>

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Error: Wrong number of argument." << std::endl;
		return 1;	
	}

	try {
		std::deque<int>	deq;
		std::list<int>		lst;
		input_check(av + 1, ac, deq, lst);
		long t1 = merge_insertion_sort_deque(deq);
		long t2 = merge_insertion_sort_list(lst);
		output(av + 1, deq, t1, t2);
	}
	catch (std::exception &e) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}
