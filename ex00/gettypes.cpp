/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettypes.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:56:45 by jholland          #+#    #+#             */
/*   Updated: 2024/11/04 14:01:04 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string.h>

static int	check_special(char const * str)
{	
	int type;

	if (isdigit(*str) || *str == '.')
		return UNKNOWN_TYPE;
	if (strncmp(str, "nan", 3) && strncmp(str, "inf", 3))
		return UNKNOWN_TYPE;
	str += 3;
	type = DOUBLE_SPECIAL_TYPE;
	if (*str == 'f')
	{
		type = FLOAT_SPECIAL_TYPE;
		str++;
	}
	while (isspace(*str))
		str++;
	if (type && *str)
		return IMPOSSIBLE_TYPE;
	return type;
}

static int	check_numeric(char const * str)
{
	int	type;
	
	type = check_special(str);
	if (type)
		return (type);
	if (!isdigit(*str) && *str != '.')
		return IMPOSSIBLE_TYPE;
	while (isdigit(*str))
		str++;
	if (*str == '.')
	{
		type = DOUBLE_TYPE;
		if (!isdigit(*(++str)))
			return IMPOSSIBLE_TYPE;
	}
	while (isdigit(*str))
		str++;
	if (*str == 'f')
	{
		type = FLOAT_TYPE;
		str++;
	}
	while (isspace(*str))
		str++;
	if (*str)
		return IMPOSSIBLE_TYPE;
	return type;
}

int	getType(char const *str)
{
	int		type;
	double	d;

	while (isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	type = check_numeric(str);
	if (type == IMPOSSIBLE_TYPE || type == FLOAT_SPECIAL_TYPE || type == DOUBLE_SPECIAL_TYPE)
		return type;
	d = strtod(str, NULL);
	if (!type && d >= 32 && d < 127)
		return (CHAR_TYPE);
	if (!type && d >= INT_MIN && d <= INT_MAX)
		return (INT_TYPE);
	if (!type)
		type = DOUBLE_TYPE;
	if (type == DOUBLE_TYPE && (d > __DBL_MAX__ || d < __DBL_MIN__))
		return IMPOSSIBLE_TYPE;
	if (type == FLOAT_TYPE && (d > __FLT_MAX__ || d < __FLT_MIN__))
		return IMPOSSIBLE_TYPE;
	return type;
}