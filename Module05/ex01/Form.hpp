/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:46:15 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:34:45 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form{
	public:
		// OCF
		Form(const std::string & name, int sign, int exe);
		Form(const Form& other);
		Form& operator=(Form other);
		virtual ~Form();
		//
		
		// getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSigneRequiredGrade() const;
		int			getExecuteRequiredGrade() const;
		//

		// Member funcs
		void	beSigned(Bureaucrat & bureaucrat);
		//

		// Utils
		void		swap(Form &tar);
		//

		// Exceptions
		class	GradeTooHighException : public std::exception {
			public:
        		virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
        		virtual const char* what() const throw();
		};
		//
	private:
		class		FormImpl;
		FormImpl	*_attr;
};

class Form::FormImpl {
	public:
		//constructors
		FormImpl(const std::string & name, int sign, int exe);

		//attributes
		const std::string	_name;
		bool				_isSigned;
		const int			_signeRequiredGrade;
		const int			_executeRequiredGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& Form);