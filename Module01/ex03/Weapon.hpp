/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:45 by yu                #+#    #+#             */
/*   Updated: 2024/01/05 23:25:47 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string type = "");
		~Weapon();
		const std::string	&getType(void) const;
		void 				setType(std::string type);
};


