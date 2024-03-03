/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:23:52 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 21:45:30 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm {
	public:
		// OCF
		ShrubberyCreationForm(const std::string & target);
		virtual ~ShrubberyCreationForm();
		//
		
		// Member funcs
		void	action() const;
		//
};