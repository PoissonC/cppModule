/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:09:55 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/04 23:34:37 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void	increase(T& num) {
	num++;
}

template <typename T>
void	output(T& value) {
	std::cout << value << " ";
}

int main( void ) {
	{
		int arr[] = {1, 2, 3, 4, 5};

		std::cout << "Before increase:" << std::endl;
		iter(arr, 5, output);
		std::cout << std::endl;
		iter(arr, 5, increase);
		std::cout << "After increase:" << std::endl;
		iter(arr, 5, output);
		std::cout << std::endl;
	}
	{
		char arr[] = {'A', 'B', 'C', 'D', 'E'};

		std::cout << "Before increase:" << std::endl;
		iter(arr, 5, output);
		std::cout << std::endl;
		iter(arr, 5, increase);
		std::cout << "After increase:" << std::endl;
		iter(arr, 5, output);
		std::cout << std::endl;
	}

	return 0;
}