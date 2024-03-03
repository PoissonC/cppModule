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

#include "AForm.hpp"

Form::Form(const std::string & name, const std::string & tar, int sign, int exe) : _attr(new FormImpl(name, tar, sign, exe)) {
	std::cout << "Default constructor of basic form called" << std::endl;
	if (sign > 150 || exe > 150) {
		delete this->_attr;
		throw GradeTooLowException();
	}
	else if (sign < 1 || exe < 1) {
		delete this->_attr;
		throw GradeTooHighException();
	}
}

Form::FormImpl::FormImpl(const std::string & name, const std::string & tar, int sign, int exe) : _name(name), _target(tar), _signeRequiredGrade(sign), _executeRequiredGrade(exe) {
	this->_isSigned = false;
}

Form::Form(const Form& other) : _attr(new FormImpl(other._attr->_name, other._attr->_target, other._attr->_signeRequiredGrade, other._attr->_executeRequiredGrade)) {
	std::cout << "Copy constructor of basic form called" << std::endl;
	this->_attr->_isSigned = other._attr->_isSigned;
}

void	Form::swap(Form &tar) {
	Form::FormImpl	*temp = this->_attr;
	this->_attr = tar._attr;
	tar._attr = temp;
}

Form&	Form::operator=(Form other) {
	std::cout << "Copy assignment operator of basic form called" << std::endl;
	this->swap(other);
	return *this;
}

Form::~Form() {
	delete this->_attr;
}

std::string	Form::getName() const {
	return this->_attr->_name;
}

std::string	Form::getTarget() const {
	return this->_attr->_target;
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

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form name: "<< form.getName() << std::endl;
    os << "Target: "<< form.getTarget() << std::endl;
	if (form.getIsSigned())
		os << "The form is signed." << std::endl;
	else
		os << "The form is not signed yet." << std::endl;
	os << "Required Grade to sign the form: " << form.getSigneRequiredGrade() << std::endl;
	os << "Required Grade to execute the form: " << form.getExecuteRequiredGrade();
    return os;
}

void	Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.signForm(*this))
		this->_attr->_isSigned = true;
}

void	Form::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->_attr->_executeRequiredGrade)
		throw GradeTooLowException();
	else if (!this->_attr->_isSigned) {
		throw NotSigned();
	}
	std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	this->action();
}

void	Form::action() const {
	throw UnDefined();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* Form::UnDefined::what() const throw() {
	return "The behavior of the form is not defined.";
}

const char* Form::NotSigned::what() const throw() {
	return "The form is not signed yet, thus it cannot be executed.";
}