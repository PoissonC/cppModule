/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/26 18:01:57 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
	// given by subject
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	// subject requires this
	{
		// create
		Animal* arr[4];
		for (int i = 0; i < 2; i++)
			arr[i] = new Dog();
		for (int i = 2; i < 4; i++)
			arr[i] = new Cat();
		// show
		for (int i = 0; i < 4; i++) {
			std::cout << "The ideas of " << i << " animal is stored at " << arr[i]->whereIsMyBrain() << " and its type is " << arr[i]->getType() << std::endl;
			arr[i]->makeSound();
			delete arr[i];
		}
	}
	// show what is shallow copy, need to modify the dog copy assignment operator
	{

		std::cout << "\033[32m";
		const Dog *i = new Dog();
		std::cout << "\033[0m";


		std::cout << "\033[33m";
		const Animal j = *i;
		std::cout << "\033[0m";

		std::cout << "\033[31m";
		const Dog k = *i;
		std::cout << "\033[0m";

		std::cout << "The ideas of i is stored at " << i->whereIsMyBrain() << " and its type is " << i->getType() << std::endl;
		std::cout << "The ideas of j is stored at " << j.whereIsMyBrain() << " and its type is " << j.getType() << std::endl;
		std::cout << "The ideas of k is stored at " << k.whereIsMyBrain() << " and its type is " << k.getType() << std::endl;
		delete i;
	}
	return 0;
}
