/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:10:58 by jholland          #+#    #+#             */
/*   Updated: 2024/11/04 19:43:55 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual	~Base() = 0;
};

class A: public Base
{
	public:
		virtual	~A();
};

class B: public Base
{
	public:
		virtual	~B();
};

class C: public Base
{
	public:
		virtual	~C();
};


Base	* generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif