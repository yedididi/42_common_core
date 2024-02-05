/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:45:56 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/10 16:27:18 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->num_value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
    this->num_value = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->num_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->num_value = raw;
}

Fixed::Fixed(const int num)
{
    this->num_value = num << this->fractional_bits;
}

Fixed::Fixed(const float num)
{
    this->num_value = roundf(num * 256);
}

float   Fixed::toFloat(void) const
{
    return ((float)this->num_value / 256);
}

int     Fixed::toInt(void) const
{
    return (this->num_value >> this->fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &fix) const
{
    if (this->getRawBits() > fix.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator<(const Fixed &fix) const
{
    if (this->getRawBits() < fix.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator>=(const Fixed &fix) const
{
    if (this->getRawBits() >= fix.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator<=(const Fixed &fix) const
{
    if (this->getRawBits() <= fix.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator==(const Fixed &fix) const
{
    if (this->getRawBits() == fix.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator!=(const Fixed &fix) const
{
    if (this->getRawBits() != fix.getRawBits())
        return (1);
    else
        return (0);
}

Fixed Fixed::operator+(const Fixed &fix) const
{
    Fixed ret(this->toFloat() + fix.toFloat());
    return (ret);
}

Fixed Fixed::operator-(const Fixed &fix) const
{
    Fixed ret(this->toFloat() - fix.toFloat());
    return (ret);
}

Fixed Fixed::operator*(const Fixed &fix) const
{
    Fixed ret(this->toFloat() * fix.toFloat());
    return (ret);
}

Fixed Fixed::operator/(const Fixed &fix) const
{
    Fixed ret(this->toFloat() / fix.toFloat());
    return (ret);
}

Fixed& Fixed::operator++(void)
{
    this->num_value++;
    return (*this);
}

Fixed& Fixed::operator--(void)
{
    this->num_value--;
    return (*this);
}

const Fixed Fixed::operator++(int)
{
    const Fixed return_Fix = *this;

    this->num_value++;
    return (return_Fix);
}

const Fixed Fixed::operator--(int)
{
    const Fixed return_Fix = *this;

    this->num_value--;
    return (return_Fix);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
    if (fix1 <= fix2)
        return (fix1);
    else
        return (fix2);
}

const Fixed& Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 <= fix2)
        return (fix1);
    else
        return (fix2);
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2)
{
    if (fix1 <= fix2)
        return (fix2);
    else
        return (fix1);
}

const Fixed& Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 <= fix2)
        return (fix2);
    else
        return (fix1);
}