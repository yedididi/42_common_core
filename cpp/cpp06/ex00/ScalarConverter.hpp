/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:41:28 by yejlee2           #+#    #+#             */
/*   Updated: 2024/01/04 15:32:54 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter operator=(const ScalarConverter &copy);
		~ScalarConverter();
		static void convert(std::string literal);
};

#endif