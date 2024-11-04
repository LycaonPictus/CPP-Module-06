/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:28 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:13:05 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				is_signed;
		unsigned int const	_grade_to_sign;
		unsigned int const	_grade_to_exec;
	
	protected:
		virtual void		formAction() const = 0;
	
	public:
						AForm(std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec);
						AForm(AForm const &);
		virtual 		~AForm();
		AForm &			operator = (AForm const &);
		
		/*   GETTERS   */
		std::string		getName( void) const;
		virtual bool	isSigned( void ) const;
		unsigned int	getGradeToSign( void ) const;
		unsigned int	getGradeToExec( void ) const;

		void			beSigned(Bureaucrat const &b);
		void			execute(Bureaucrat const &b) const;
		
		class GradeTooHighException: public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return "The grade of the form is too high.";
			}
		};
		class GradeTooLowException: public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return "The grade of the form is too low.";
			}
		};
		class NotSignedFormException: public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return "The form is not signed.";
			}
		};
};

std::ostream & operator << (std::ostream &, AForm const &);

#endif // A_FORM_HPP