/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:55:30 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 13:44:05 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	protected:
		std::string const	_name;
		unsigned int		_grade;
	public:
							Bureaucrat(std::string const name);
							Bureaucrat(Bureaucrat const &);
							~Bureaucrat();
		Bureaucrat &		operator = (Bureaucrat const &);
	
	/* GETTERS */
		std::string			getName() const;
		unsigned int		getGrade() const;

		void				setGrade(unsigned int grade);
	/* OPERATORS */
		Bureaucrat			operator ++ (void);
		Bureaucrat			operator -- (void);
		Bureaucrat			operator ++ (int);
		Bureaucrat			operator -- (int);

		void				signForm(AForm &f);
		void				executeForm(AForm &f);
		
		class GradeTooHighException: public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return "The grade of bureaucrat is too high.";
			}
		};
		class GradeTooLowException: public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return "The grade of bureaucrat is too low.";
			}
		};
};

std::ostream & operator << (std::ostream &, Bureaucrat const &);

#endif // BUREAUCRAT_HPP