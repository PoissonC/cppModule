/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/24 18:45:22 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>


inline static void	checker(std::deque<int> & deq, std::vector<int> & vec) {
	int	size = deq.size();
	if (size == (int)vec.size()) {
		for (int i = 0; i < size; i++) {
			if (deq[i] != vec[i]) {
				std::cerr << "Not correct.\n";
				return ;
			}
		}
	}
	else
		std::cerr << "Not correct.\n";
}

inline static void	checker(std::list<int> & lst, std::vector<int> & vec) {
	int	size = lst.size();
	if (size == (int)vec.size()) {
		int i =0;
		for (std::list<int>::iterator it = lst.begin(); it != lst.end() && i < size; it++, i++) {
			if (*it != vec[i]) {
				std::cerr << "Not correct.\n";
				return ;
			}
		}
	}
	else
		std::cerr << "Not correct.\n";
}

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Error: Wrong number of argument." << std::endl;
		return 1;
	}

	try {
		std::deque<int>	deq;
		std::list<int>	lst;
		input_check(av + 1, ac, deq, lst);
		if (ac == 2) {
			output(av + 1, deq, 0, 0);
			return 0;
		}
		std::vector<int>	vec;
		for (int i = 0; i < (int)deq.size(); i++)
			vec.push_back(deq[i]);
		std::sort(vec.begin(), vec.end());
		long t1 = merge_insertion_sort_deque(deq);
		checker(deq, vec);
		long t2 = merge_insertion_sort_list(lst);
		checker(lst, vec);
		output(av + 1, deq, t1, t2);
	}
	catch (std::exception &e) {
		std::cout << "Error " << std::endl;
		return 1;
	}
	return 0;
}
