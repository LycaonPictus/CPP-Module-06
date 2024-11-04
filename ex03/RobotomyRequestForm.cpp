/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:05:27 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:27:49 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <math.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("robotomy request", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm(other), _target(other.getTarget()){}

RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const &){return (*this);}

std::string RobotomyRequestForm::getTarget() const{return this->_target;}

void	RobotomyRequestForm::formAction() const
{
	std::cout << "Trrr drr, trtrtr. ";
	srand((unsigned int)time(NULL));
	int r = rand();
	if (r % 2)
		std::cout << this->_target << " has been robotomized successfully.\n";
	else
		std::cout << "The robotomy of " << this->_target << " failed.\n";
}
