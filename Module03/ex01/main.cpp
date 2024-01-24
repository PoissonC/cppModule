/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 20:53:49 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap a("Heeeeerooooo");

	a.attack("Enemy");
	a.takeDamage(5);
	a.beRepaired(10);
	a.takeDamage(20);
	a.beRepaired(5);
	a.guardGate();
	a.takeDamage(1000);
	a.attack("Enemy");
	a.guardGate();
	a.beRepaired(10);

	return 0;
}
