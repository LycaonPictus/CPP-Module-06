/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:23:18 by jholland          #+#    #+#             */
/*   Updated: 2024/11/04 13:43:12 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <limits.h>

int		getType(char const *str);
void	print_correct_type(char const * str, int type);

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter & ScalarConverter::operator = (ScalarConverter const &){return *this;}

void	ScalarConverter::convert(char const * str)
{
	print_correct_type(str, getType(str));
}
