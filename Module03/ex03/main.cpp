/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 21:14:09 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap d("DIAMOND");

	d.attack("Enemy");
	d.takeDamage(5);
	d.beRepaired(10);
	d.takeDamage(20);
	d.beRepaired(5);
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();
	d.takeDamage(1000);
	d.attack("Enemy");
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();

	return 0;
}
