/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:26:01 by yu                #+#    #+#             */
/*   Updated: 2024/01/11 17:45:36 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie(const std::string& name = "");
		~Zombie(void);
		void	announce(void);
		void	setName(const std::string& name);
	private:
		std::string	name;
};

#endif