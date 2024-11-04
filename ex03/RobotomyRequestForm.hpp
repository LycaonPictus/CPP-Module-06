/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:06:09 by jholland          #+#    #+#             */
/*   Updated: 2024/10/29 15:16:33 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string const	_target;
		
	protected:
		virtual void		formAction() const;

	public:
						RobotomyRequestForm(std::string target);
						RobotomyRequestForm(RobotomyRequestForm const &);
		virtual 		~RobotomyRequestForm();
		RobotomyRequestForm &			operator = (RobotomyRequestForm const &);

		std::string		getTarget() const;
};

#endif