/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/06 21:15:33 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap a("...Hero...");

	a.attack("Enemy");
	a.takeDamage(5);
	a.beRepaired(10);
	a.takeDamage(20);
	a.beRepaired(5);
	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();
	a.takeDamage(1000);
	a.attack("Enemy");

	return 0;
}
