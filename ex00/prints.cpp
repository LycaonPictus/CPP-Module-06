/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:06:08 by jholland          #+#    #+#             */
/*   Updated: 2024/11/04 14:41:22 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <math.h>

static void	print_impossible(void)
{
	std::cout << "char: "	<< "impossible" << std::endl;
	std::cout << "int: "	<< "impossible" << std::endl;
	std::cout << "float: "	<< "impossible" << std::endl;
	std::cout << "double: "	<< "impossible" << std::endl;
}

static void	print_float_special(float const fs)
{
	std::cout << "char: "	<< "impossible" 			<< std::endl;
	std::cout << "int: "	<< "impossible"				<< std::endl;
	std::cout << "float: "	<< fs << "f"	 			<< std::endl;
	std::cout << "double: "	<< static_cast<double>(fs)	<< std::endl;
}

static void	print_double_special(double const ds)
{
	std::cout << "char: "	<< "impossible" 					<< std::endl;
	std::cout << "int: "	<< "impossible"						<< std::endl;
	std::cout << "float: "	<< static_cast<float>(ds) << "f"	<< std::endl;
	std::cout << "double: "	<< ds								<< std::endl;
}

static void	print_char(char const c)
{
	std::cout << "char: "	<<	c								<< std::endl;
	std::cout << "int: "	<<	static_cast<int>(c)				<< std::endl;
	std::cout << "float: "	<<	static_cast<float>(c) << ".0f"	<< std::endl;
	std::cout << "double: "	<<	static_cast<double>(c) << ".0"	<< std::endl;
}

static void	print_int(int const i)
{
	if (i >= 32 && i < 127)
		std::cout << "char: "	<<	static_cast<char>(i)			<< std::endl;
	else if (i >= CHAR_MIN && i <= CHAR_MAX)
		std::cout << "char: "	<<	"Non displayable"				<< std::endl;
	else
		std::cout << "char: "	<<	"impossible"					<< std::endl;

	std::cout << "int: "	<<	i								<< std::endl;
	std::cout << "float: "	<<	static_cast<float>(i) << ".0f"	<< std::endl;
	std::cout << "double: "	<<	static_cast<double>(i) << ".0"	<< std::endl;
}

static void	print_float(float const f)
{
	std::string	cero = (f == roundf(f) && f < 1e6 && f >= 1e-4 ? ".0" : "");
	
	if (f >= 32 && f < 127)
		std::cout << "char: "	<<	static_cast<char>(f)			<< std::endl;
	else if (f >= CHAR_MIN && f <= CHAR_MAX)
		std::cout << "char: "	<<	"Non displayable"				<< std::endl;
	else
		std::cout << "char: "	<<	"impossible"					<< std::endl;

	if (f >= INT_MIN && f <= INT_MAX)
		std::cout << "int: "	<<	static_cast<int>(f)				<< std::endl;
	else
		std::cout << "int: "	<<	"impossible"					<< std::endl;

	std::cout << "float: "	<<	f << cero << "f"				<< std::endl;
	std::cout << "double: "	<<	static_cast<double>(f) << cero	<< std::endl;
}

static void	print_double(double const d)
{
	std::string	cero = (d == roundf(d) && d < 1e6 && d >= 1e-4 ? ".0" : "");

	if (d >= 32 && d < 127)
		std::cout << "char: "	<<	static_cast<char>(d)					<< std::endl;
	else if (d >= CHAR_MIN && d <= CHAR_MAX)
		std::cout << "char: "	<<	"Non displayable"						<< std::endl;
	else
		std::cout << "char: "	<<	"impossible"							<< std::endl;

	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << "int: "	<<	static_cast<int>(d)						<< std::endl;
	else
		std::cout << "int: "	<<	"impossible"							<< std::endl;

	if (d >= __FLT_MIN__ && d <= __FLT_MAX__)
		std::cout << "float: "	<<	static_cast<float>(d) << cero << "f"	<< std::endl;
	else
		std::cout << "float: "	<<	"impossible"							<< std::endl;

	std::cout << "double: "	<<	d << cero								<< std::endl;
}

void	print_correct_type(char const * str, int type)
{
	switch (type)
	{
		case IMPOSSIBLE_TYPE:
			print_impossible();
			break;
		case FLOAT_SPECIAL_TYPE:
			print_float_special(atof(str));
			break;
		case DOUBLE_SPECIAL_TYPE:
			print_double_special(strtod(str, NULL));
			break;
		case CHAR_TYPE:
			print_char(static_cast<char>(atoi(str)));
			break;
		case INT_TYPE:
			print_int(atoi(str));
			break;
		case FLOAT_TYPE:
			print_float(atof(str));
			break;
		case DOUBLE_TYPE:
			print_double(strtod(str, NULL));
			break;
		default:
			std::cout << "Error. Type not recgnized\n";
	}
}