/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 22:29:53 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
	// vector
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	try {
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const NotFoundException& e) {
		std::cerr << "Exception: " <<  e.what() << std::endl;
	}

	// list
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try {
		std::list<int>::iterator it = easyfind(lst, 6);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const NotFoundException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
