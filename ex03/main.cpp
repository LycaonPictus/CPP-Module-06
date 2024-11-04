/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:24 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 16:55:16 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main( void )
{
	Intern i;
	AForm *rr = i.makeForm("robotomy request", "Alice");
	Bureaucrat bob("Bob");
	bob.setGrade(30);
	bob.executeForm(*rr);
	bob.signForm(*rr);
	bob.executeForm(*rr);
	delete rr;
}