/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:08:49 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:02:14 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name): _name(name), _grade(150){}

Bureaucrat::Bureaucrat(Bureaucrat const &other): _name(other._name), _grade(other._grade){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & other)
{
	this->_grade = other._grade;
	return *this;
}

std::string Bureaucrat::getName() const {return this->_name;}

unsigned int Bureaucrat::getGrade() const {return this->_grade;}

void	Bureaucrat::setGrade(unsigned int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat Bureaucrat::operator ++ (void)
{
	Bureaucrat tmp = *this;
	this->setGrade(this->_grade - 1);
	return (tmp);
}

Bureaucrat Bureaucrat::operator -- (void)
{
	Bureaucrat tmp = *this;
	this->setGrade(this->_grade + 1);
	return (tmp);
}

Bureaucrat Bureaucrat::operator ++ (int)
{
	this->setGrade(this->_grade - 1);
	return (*this);
}

Bureaucrat Bureaucrat::operator -- (int)
{
	this->setGrade(this->_grade + 1);
	return (*this);
}

std::ostream & operator << (std::ostream &out, Bureaucrat const &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << ".\n";
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << "\n";
	}
}

void	Bureaucrat::executeForm(AForm &f)
{
	try
	{
		f.execute(*this);
		std::cout << this->getName() << " executed " << f.getName() << ".\n";
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " << f.getName() << " because " << e.what() << "\n";
	}
}