/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:36:45 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 16:54:39 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm *Intern::shrubberyForm(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::robotomyForm(std::string const target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::pardonForm(std::string const target)
{
	return (new PresidentialPardonForm(target));
}


AForm	*Intern::makeForm(std::string const form_name, std::string const target)
{	
	static std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static AForm *(Intern::*form_creation[3])(std::string const) = {&Intern::shrubberyForm, &Intern::robotomyForm, &Intern::pardonForm};
	for (int i = 0; i < 3; i++)
		if (form_name == form_names[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (this->*form_creation[i])(target);
		}
	std::cout << "Form '" << form_name << "' doesn't exist.\n";
	return NULL;
}