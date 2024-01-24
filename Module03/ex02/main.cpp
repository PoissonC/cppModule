/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 20:56:48 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {
	FragTrap a("Hero...");

	a.attack("Enemy");
	a.takeDamage(5);
	a.beRepaired(10);
	a.takeDamage(20);
	a.beRepaired(5);
	a.highFivesGuys();
	a.takeDamage(1000);
	a.attack("Enemy");
	a.beRepaired(5);
	a.highFivesGuys();

	return 0;
}
