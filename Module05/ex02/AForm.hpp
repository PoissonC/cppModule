/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                         :+:      :+:    :+:   */
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

class	AForm{
	public:
		// OCF
		AForm(const std::string & name, int sign, int exe);
		AForm(const AForm& other);
		virtual AForm& operator=(AForm other);
		virtual ~AForm();
		//
		
		// getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSigneRequiredGrade() const;
		int			getExecuteRequiredGrade() const;
		//

		// Member funcs
		void			beSigned(Bureaucrat & bureaucrat);
		void			execute(Bureaucrat const & executor) const;
		virtual void	action() const;
		//

		// Utils
		void		swap(AForm &tar);
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
		class	UnDefined : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class	NotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		//
	private:
		class		AFormImpl;
		AFormImpl	*_attr;
};

class AForm::AFormImpl {
	public:
		//constructors
		AFormImpl(const std::string & name, int sign, int exe);

		//attributes
		const std::string	_name;
		bool				_isSigned;
		const int			_signeRequiredGrade;
		const int			_executeRequiredGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);