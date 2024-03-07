/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:09:55 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 21:45:06 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <exception>

int main( void ) {
	Array<int>	arr;
	Array<int>	copy;

	try {
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

// #include <iostream>
// #include <Array.hpp>
// #include <cstdlib> 

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }