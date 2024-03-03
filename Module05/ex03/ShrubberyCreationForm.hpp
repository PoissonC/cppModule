/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:23:52 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 17:56:37 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm {
	public:
		// OCF
		ShrubberyCreationForm(const std::string & name, const std::string & target);
		virtual ~ShrubberyCreationForm();
		//
		
		// Member funcs
		void	action() const;
		//
};