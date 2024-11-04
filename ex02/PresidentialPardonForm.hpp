/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:06:09 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:17:09 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string const	_target;
		
	protected:
		virtual void		formAction() const;

	public:
						PresidentialPardonForm(std::string target);
						PresidentialPardonForm(PresidentialPardonForm const &);
		virtual 		~PresidentialPardonForm();
		PresidentialPardonForm &			operator = (PresidentialPardonForm const &);

		std::string		getTarget() const;
};

#endif