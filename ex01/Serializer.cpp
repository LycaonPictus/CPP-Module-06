/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:23:18 by jholland          #+#    #+#             */
/*   Updated: 2024/11/04 18:53:18 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdlib.h>
#include <limits.h>

int		getType(char const *str);
void	print_correct_type(char const * str, int type);

Serializer::Serializer(){}

Serializer::Serializer(Serializer const &){}

Serializer::~Serializer(){}

Serializer & Serializer::operator = (Serializer const &){return *this;}

uintptr_t	Serializer::serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data	*Serializer::deserialize(uintptr_t	ptr)
{
	return (reinterpret_cast<Data *>(ptr));
}