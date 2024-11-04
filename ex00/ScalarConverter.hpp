/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:55:30 by jholland          #+#    #+#             */
/*   Updated: 2024/11/04 13:48:15 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <limits.h>
# include <stdlib.h>

enum	e_type
{
	IMPOSSIBLE_TYPE = -1,
	UNKNOWN_TYPE,
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	FLOAT_SPECIAL_TYPE,
	DOUBLE_TYPE,
	DOUBLE_SPECIAL_TYPE
};

class ScalarConverter
{
	private:
							ScalarConverter();
	public:
							ScalarConverter(ScalarConverter const &);
							~ScalarConverter();
		ScalarConverter &	operator = (ScalarConverter const &);
	
		static void	convert(char const *);
};

#endif // SCALAR_CONVERTER_HPP