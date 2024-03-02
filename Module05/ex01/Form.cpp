/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:44:47 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string & name, int sign, int exe) : _attr(new FormImpl(name, sign, exe)) {
	if (sign > 150 || exe > 150) {
		delete this->_attr;
		throw GradeTooLowException();
	}
	else if (sign < 1 || exe < 1) {
		delete this->_attr;
		throw GradeTooHighException();
	}
}

Form::FormImpl::FormImpl(const std::string & name, int sign, int exe) : _name(name), _signeRequiredGrade(sign), _executeRequiredGrade(exe) {
	this->_isSigned = false;
}

Form::Form(const Form& other) : _attr(new FormImpl(other._attr->_name, other._attr->_signeRequiredGrade, other._attr->_executeRequiredGrade)) {
	this->_attr->_isSigned = other._attr->_isSigned;
}

void	Form::swap(Form &tar) {
	Form::FormImpl	*temp = this->_attr;
	this->_attr = tar._attr;
	tar._attr = temp;
}

Form&	Form::operator=(Form other) {
	this->swap(other);
	return *this;
}

Form::~Form() {
	delete this->_attr;
}

std::string	Form::getName() const {
	return this->_attr->_name;
}

bool	Form::getIsSigned() const {
	return this->_attr->_isSigned;
}

int		Form::getSigneRequiredGrade() const {
	return this->_attr->_signeRequiredGrade;
}

int		Form::getExecuteRequiredGrade() const {
	return this->_attr->_executeRequiredGrade;
}

std::ostream& operator<<(std::ostream& os, const Form& Form) {
    os << "Form name: "<< Form.getName() << std::endl;
	if (Form.getIsSigned())
		os << "The form is signed." << std::endl;
	else
		os << "The form is not signed yet." << std::endl;
	os << "Required Grade to sign the form: " << Form.getSigneRequiredGrade() << std::endl;
	os << "Required Grade to execute the form: " << Form.getExecuteRequiredGrade() << std::endl;
    return os;
}

void	Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.signForm(*this))
		this->_attr->_isSigned = true;
}


const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}
