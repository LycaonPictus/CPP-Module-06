/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:36:55 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 16:54:32 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *shrubberyForm(std::string const target);
		AForm *robotomyForm(std::string const target);
		AForm *pardonForm(std::string const target);
	public:
		AForm	*makeForm(std::string const form_name, std::string const target);
};

#endif