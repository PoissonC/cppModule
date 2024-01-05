/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/06 00:41:35 by yu               ###   ########.fr       */
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

	return 0;
}
