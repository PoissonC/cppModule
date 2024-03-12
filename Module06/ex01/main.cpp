/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:24:14 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/12 23:15:06 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data data[2];
	std::cout << "The size of type Data is " << sizeof(Data) << std::endl;
	uintptr_t	uintptr = Serializer::serialize(data);
	// This test iterates through the serialized uintptr
	std::cout << "Try to find the memory address of the sencond element of the data array." << std::endl;
	std::cout << "The memory address of the first element is " << uintptr << std::endl;
	std::cout << "The hex presentation is " << data << std::endl;
	for (int i = 0; i < 100; i++) {
		// Check with 1 unit displacement (memory address)
		if (Serializer::deserialize(uintptr++) == data + 1) {
			std::cout << "Success at steps " << i << std::endl;
			std::cout << "The memory address of the second element is " << --uintptr << std::endl;
			std::cout << "The hex presentation is " << data + 1<< std::endl;
			break;
		}
		else {
			std::cout << "Fail at steps " << i << std::endl;
		}
	}
	return (0);
}