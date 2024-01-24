/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 20:27:56 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a("Herooooo");

	a.attack("Enemy");
	a.takeDamage(5);
	a.beRepaired(10);
	for (int i = 0; i < 10; i++)
		a.beRepaired(150);
	a.attack("Enemy");
	a.takeDamage(20);
	a.attack("Enemy");
	a.beRepaired(5);
	a.takeDamage(2000);
	a.beRepaired(5);
	a.attack("Enemy");

	return 0;
}
