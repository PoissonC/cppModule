/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:23:52 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 17:13:22 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	PresidentialPardonForm : public Form {
	public:
		// OCF
		PresidentialPardonForm(const std::string & target);
		virtual ~PresidentialPardonForm();
		//
		
		// Member funcs
		void	action() const;
		//
};