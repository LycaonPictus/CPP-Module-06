/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:30 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:13:37 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec): _name(name), is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (_grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_to_sign > 150)
		throw AForm::GradeTooLowException();
	if (_grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_to_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other):_name(other.getName()), is_signed(other.isSigned()), _grade_to_sign(other.getGradeToSign()), _grade_to_exec(other.getGradeToExec())
{
	if (_grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_to_sign > 150)
		throw AForm::GradeTooLowException();
	if (_grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_to_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(){}
AForm & AForm::operator = (AForm const &){return (*this);}

std::string		AForm::getName( void ) const {return this->_name;}
bool 			AForm::isSigned( void ) const {return this->is_signed;}
unsigned int	AForm::getGradeToSign( void ) const {return this->_grade_to_sign;}
unsigned int	AForm::getGradeToExec( void ) const {return this->_grade_to_exec;}

std::ostream & operator << (std::ostream &out, AForm const &form)
{
	out << "Form '" << form.getName() << "' (";
	out << (!form.isSigned() ? "not " : "") << "signed). Grade to sign: ";
	out << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExec() << ".\n";
	return out;
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= this->getGradeToSign())
		this->is_signed = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &b) const
{
	if (!this->isSigned())
		throw AForm::NotSignedFormException();
	else if (b.getGrade() <= this->getGradeToExec())
		this->formAction();
	else
		throw Bureaucrat::GradeTooLowException();
}