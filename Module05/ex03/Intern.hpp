/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:05:40 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 21:57:41 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		// OCF
		Intern();
		Intern(const Intern & other);
		Intern & operator=(const Intern & other);
		~Intern();
		//

		// Member funcs
		AForm *	makeForm(const std::string & formName, const std::string & target);
		//
	private:
		class	Forms {
			std::string	formName;
			
		};
};
