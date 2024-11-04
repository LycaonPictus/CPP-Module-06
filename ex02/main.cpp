/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:24 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:01:42 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	Bureaucrat b("Flanders");
	ShrubberyCreationForm sc("home");
	RobotomyRequestForm rr("Paul");
	PresidentialPardonForm pp("Billy");
	b.signForm(sc);
	b.executeForm(sc);
	b.setGrade(140);
	b.signForm(sc);
	b.executeForm(sc);
	b.setGrade(120);
	b.signForm(sc);
	b.executeForm(sc);
	b.setGrade(6);
	b.signForm(rr);
	b.executeForm(rr);
	b.signForm(pp);
	b.executeForm(pp);
}