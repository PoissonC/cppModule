/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:23:52 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 17:13:22 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time(), to seed the random number generator

class	RobotomyRequestForm : public Form {
	public:
		// OCF
		RobotomyRequestForm(const std::string & target);
		virtual ~RobotomyRequestForm();
		//
		
		// Member funcs
		void	action() const;
		//
};