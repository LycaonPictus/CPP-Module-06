/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:05:27 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:17:14 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("presidential pardon", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): AForm(other), _target(other.getTarget()){}

PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const &){return (*this);}

std::string PresidentialPardonForm::getTarget() const{return this->_target;}



void	PresidentialPardonForm::formAction() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}