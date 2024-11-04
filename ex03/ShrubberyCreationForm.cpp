/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:05:27 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:18:09 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("shrubbery creation", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): AForm(other), _target(other.getTarget()){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm const &){return (*this);}

std::string ShrubberyCreationForm::getTarget() const{return this->_target;}

void	ShrubberyCreationForm::formAction() const
{
	std::ofstream	file;
	const char *	file_name;
	file_name = (this->_target + "_shrubbery").c_str();
	file.open(file_name);
	if (file.fail())
	{
		std::cerr << "Cannot create file " + this->_target + "_shrubbery.\n";
		return;
	}
	file << this->_target << std::endl;
	file << "└ root/\n";
	file << "  └ my_work/\n";
	file << "    ├ branch1/\n";
	file << "    │ ├ leaf1.jpg\n";
	file << "    │ ├ leaf2.jpg\n";
	file << "    │ └ leaf3.jpg\n";
	file << "    ├ branch2/\n";
	file << "    │ ├ leaf1.jpg\n";
	file << "    │ ├ leaf2.jpg\n";
	file << "    │ └ leaf3.jpg\n";
	file << "    └ branch3/\n";
	file << "      ├ leaf1.jpg\n";
	file << "      ├ leaf2.jpg\n";
	file << "      └ leaf3.jpg\n";
	file.close();
}
