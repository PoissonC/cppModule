/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/04/26 18:28:00 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


int main() {
	// vector
	int arr[] = {1, 2, 3, 4, 5};
	std::cout << "Vector tests: " << std::endl;
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::vector<int>::iterator it = easyfind(vec, 5);
	if (it != vec.end())
		std::cout << "Found value: " << *it << std::endl;
	else
		std::cout << "Value not found." << std::endl;

	// Not found test
	it = easyfind(vec, 6);
	if (it != vec.end())
		std::cout << "Found value: " << *it << std::endl;
	else
		std::cout << "Value not found." << std::endl;
	// dup
	int arr_dup[] = {1, 2, 3, 4, 5, 2 ,3 ,2};
	std::vector<int> vec_dup(arr_dup, arr_dup + sizeof(arr) / sizeof(arr_dup[0]));
	it = easyfind(vec_dup, 2);
	if (it != vec.end()) {
		std::cout << "Found value: " << *it << std::endl;
		std::cout << "The value of the previous element is : " << *(--it) << std::endl; it++;
		std::cout << "The value of the next element is : " << *(++it) << std::endl;
	}
	else
		std::cout << "Value not found." << std::endl;
	// list
	std::cout << "List tests: " << std::endl;
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::list<int>::iterator it_lst = easyfind(lst, 5);
	if (it_lst != lst.end()) {
		std::cout << "Found value: " << *it_lst << std::endl;
	}
	else
		std::cout << "Value not found." << std::endl;
	// deque
	std::cout << "Deque tests: " << std::endl;
	std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::deque<int>::iterator it_deq = easyfind(deq, 5);
	if (it_deq != deq.end()) {
		std::cout << "Found value: " << *it_deq << std::endl;
	}
	else
		std::cout << "Value not found." << std::endl;
}
