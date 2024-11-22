/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:15:45 by jholland          #+#    #+#             */
/*   Updated: 2024/11/22 14:02:53 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <wait.h>

Base::~Base(){}
A::~A(){}
B::~B(){}
C::~C(){}

Base	*generate(void)
{
	unsigned seed =(time(0) * 1000 + clock());
	srand(seed);
	int r = rand() % 3;
	
	//srand((unsigned int)time(NULL));
	//int r = rand();
	switch (r % 3)
	{
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 2:
			return (new C());
			break;
		default:
			return (NULL);
	}
	usleep(100);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C";
	else
		std::cout << "Unknown";
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A";
		(void)a;
		return;
	}
	catch(std::exception &e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B";
		(void)b;
		return;
	}
	catch(std::exception &e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C";
		(void)c;
		return;
	}
	catch(std::exception &e){}
}
