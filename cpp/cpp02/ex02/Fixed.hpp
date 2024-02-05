/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:46:16 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/10 11:56:02 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 num_value;
        static const int    fractional_bits = 8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed &rhs);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float   toFloat(void) const;
        int     toInt(void) const;
        bool operator>(const Fixed &fix) const;
        bool operator<(const Fixed &fix) const;
        bool operator>=(const Fixed &fix) const;
        bool operator<=(const Fixed &fix) const;
        bool operator==(const Fixed &fix) const;
        bool operator!=(const Fixed &fix) const;
        Fixed operator+(const Fixed &fix) const;
        Fixed operator-(const Fixed &fix) const;
        Fixed operator*(const Fixed &fix) const;
        Fixed operator/(const Fixed &fix) const;
        Fixed& operator++(void);
        Fixed& operator--(void);
        const Fixed operator++(int);
        const Fixed operator--(int);
        static Fixed &min(Fixed &fix1, Fixed &fix2);
		static const Fixed &min(const Fixed &fix1, const Fixed &fix2);
		static Fixed &max(Fixed &fix1, Fixed &fix2);
		static const Fixed &max(const Fixed &fix1, const Fixed &fix2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fix);

#endif