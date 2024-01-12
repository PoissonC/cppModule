/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:01 by yu                #+#    #+#             */
/*   Updated: 2024/01/05 23:25:03 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	
		// A structure to map strings to member function pointers
		struct Complaint {
			std::string level;
			void (Harl::*method)();
		};

	public:
		void	complain(std::string level);
};


