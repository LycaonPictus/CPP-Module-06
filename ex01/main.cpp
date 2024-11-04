/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:06:36 by jholland          #+#    #+#             */
/*   Updated: 2024/11/04 19:01:13 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdlib.h>
#include <iostream>

int main(void)
{
	Data d1 = {"AAAAA", 42, 0};
	uintptr_t	ptr1 = Serializer::serialize(&d1);
	Data d2 = {"BBBBB", 43, ptr1};

	std::cout << "d2:\n\t{";
	std::cout << d2.string << " - ";
	std::cout << d2.number << " - ";
	std::cout << d2.next << "}\n";
	
	std::cout << "d1:\n\t{";
	std::cout << Serializer::deserialize(d2.next)->string << " - ";
	std::cout << Serializer::deserialize(d2.next)->number << " - ";
	std::cout << Serializer::deserialize(d2.next)->next << "}\n\n";

	std::cout << "d1 original address:\n\t" << &d1 << std::endl;
	std::cout << "d1 re-serialization address:\n\t" << Serializer::deserialize(Serializer::serialize(&d1)) << std::endl;
}