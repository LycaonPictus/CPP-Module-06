/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:35:38 by jholland          #+#    #+#             */
/*   Updated: 2024/11/04 20:17:21 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main(void)
{
	Base *B;
	for (int i = 0 ; i < 10 ; i++)
	{
		B = generate();
		std::cout << "Ptr: [";
		identify(B);
		std::cout << "] - ";
		std::cout << "Ref: [";
		identify(*B);
		std::cout << "]\n";
		delete B;
	}
}