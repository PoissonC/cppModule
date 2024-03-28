/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:09:55 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/28 16:26:45 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <exception>

int main( void ) {
	Array<int>	arr = Array<int>();
	Array<int>	copy;

	try {
		std::cout << "arr size: " << arr.size() << std::endl;
		std::cout << arr[0] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Default: ";
		arr = Array<int>(10);
		for (int i = 0; i < 10; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "arr size: " << arr.size() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		arr = Array<int>(10);
		std::cout << "arr : ";
		for (int i = 0; i < 10; i++) {
			arr[i] = i + 1;
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		copy = arr;
		std::cout << "copy: ";
		for (int i = 0; i < 10; i++) {
			std::cout << copy[i] << " ";		
		}
		std::cout << std::endl;
		const Array<int>	copy2(copy);
		std::cout << "const copy: ";
		for (int i = 0; i < 10; i++) {
			std::cout << copy2[i] << " ";		
		}
		std::cout << std::endl;
		//Modify arr
		std::cout << "Mod arr: ";
		for (int i = 0; i < 10; i++) {
			arr[i]++;
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		//Test copy
		std::cout << "Test copy: ";
		for (int i = 0; i < 10; i++) {
			std::cout << copy[i] << " ";		
		}
		std::cout << std::endl;
		std::cout << "Test const copy: ";
		for (int i = 0; i < 10; i++) {
			std::cout << copy2[i] << " ";		
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	Array<char> str(100);
	try {
		std::cout << "str : ";
		for (int i = 0; i < 10; i++) {
			str[i] = i + 'A';
			std::cout << str[i] << " ";
		}
		std::cout << std::endl;
		Array<char> copy3 = str;
		std::cout << "copy: ";
		for (int i = 0; i < 10; i++) {
			std::cout << copy3[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
