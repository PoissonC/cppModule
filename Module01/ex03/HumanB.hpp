/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:34 by yu                #+#    #+#             */
/*   Updated: 2024/01/05 23:25:35 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon		*weapon;
		bool	is_weapon;

	public:
		HumanB(std::string name = "");
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);
};
