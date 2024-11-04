/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:06:09 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:17:03 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string const	_target;
		
	protected:
		virtual void		formAction() const;

	public:
						ShrubberyCreationForm(std::string target);
						ShrubberyCreationForm(ShrubberyCreationForm const &);
		virtual 		~ShrubberyCreationForm();
		ShrubberyCreationForm &			operator = (ShrubberyCreationForm const &);

		std::string		getTarget() const;
};

#endif