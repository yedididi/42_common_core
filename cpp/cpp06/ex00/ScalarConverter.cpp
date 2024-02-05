/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:41:14 by yejlee2           #+#    #+#             */
/*   Updated: 2024/01/25 13:59:16 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    if (&copy != this)
    {
    }
}

ScalarConverter ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (&copy != this)
    {
    }
    return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

bool ft_isinf(double value)
{
    return (value != 0 && value * 2 == value);
}

bool ft_isnan(double value)
{
    return (value != value);
}

void    ConvertChar(double value)
{
    if ((value > 31 && value < 127) && ft_isinf(value) == 0 && ft_isnan(value) == 0)
        std::cout << "char is: " << "'" << static_cast<char>(value)  << "'" << std::endl;
    else if (ft_isinf(value) == 1 || ft_isnan(value) == 1)
        std::cout << "char is: impossible" << std::endl;
    else
        std::cout << "char is: Non displayable" << std::endl;
}

void    ConvertInt(double value)
{
    int converted;

    converted = static_cast<int>(value);
    if (value < 2147483647 && value > -2147483648 && ft_isinf(value) == 0 && ft_isnan(value) == 0)
        std::cout << "int is: " << converted << std::endl;
    else if (ft_isinf(value) == 1 || ft_isnan(value) == 1)
        std::cout << "int is: impossible" << std::endl;
    else
        std::cout << "int is: out of range" << std::endl;
}

void    ConvertFloat(double value)
{
    float converted;

    converted = static_cast<float>(value);
    if (ft_isinf(value) == 1 || ft_isnan(value) == 1)
        std::cout << "float is: " << value << "f" << std::endl;
    else if (converted == static_cast<int>(value))
        std::cout << "float is: " << converted << ".0" << "f" << std::endl;
    else
        std::cout << "float is: " << converted << "f" << std::endl;
}

void    ConvertDouble(double value)
{
    double converted;

    converted = static_cast<double>(value);
    if (ft_isinf(value) == 1 || ft_isnan(value) == 1)
        std::cout << "double is: " << value << std::endl;
    else if (converted == static_cast<int>(value))
        std::cout << "double is: " << converted << ".0" << std::endl;
    else
        std::cout << "double is: " << converted << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	double value;
    char *after_tod;

    value = std::strtod(literal.c_str(), &after_tod);
    if (literal.c_str() == after_tod)
        std::cout << "char is: impossible\nint is: impossible\nfloat is: impossible\ndouble is: impossible\n";
    else
    {
        ConvertChar(value);
        ConvertInt(value);
        ConvertFloat(value);
        ConvertDouble(value);
    }
}