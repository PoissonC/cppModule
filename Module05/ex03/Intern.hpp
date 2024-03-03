/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:05:40 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 22:47:32 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Form*	createPPF(const std::string & tar);
Form*	createRRF(const std::string & tar);
Form*	createSCF(const std::string & tar);

class Intern {
	public:
		// OCF
		Intern();
		Intern(const Intern & other);
		Intern & operator=(const Intern & other);
		~Intern();
		//

		// Member funcs
		Form*	makeForm(const std::string & formName, const std::string & target);
		//
	private:
		struct	s_forms {
			std::string	formName;
			Form*		(*formFactory)(const std::string & tar);
		};
};
