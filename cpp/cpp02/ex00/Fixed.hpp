/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:53:51 by yejlee2           #+#    #+#             */
/*   Updated: 2023/11/10 13:50:21 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 num_value;
        static const int    fractional_bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed &rhs);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif