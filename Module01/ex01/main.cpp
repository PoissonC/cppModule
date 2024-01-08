/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:55 by yu                #+#    #+#             */
/*   Updated: 2024/01/08 15:54:31 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void) {
	Zombie *h1 = zombieHorde(10, "yu");
	for (int i = 0; i < 10; i++)
		h1[i].announce();
	Zombie *h2 = zombieHorde(20, "foo");
	for (int i = 0; i < 20; i++)
		h2[i].announce();
	delete[] h1;
	delete[] h2;
}
