/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:56:43 by yejlee2           #+#    #+#             */
/*   Updated: 2024/01/04 16:22:58 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer &copy)
{
    if (&copy != this)
    {

    }
}

Serializer Serializer::operator=(const Serializer &copy)
{
    if (&copy != this)
    {
        
    }
    return (*this);
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t ret_int;

    ret_int = reinterpret_cast<uintptr_t>(ptr);
    return (ret_int);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ret_ptr;

    ret_ptr = reinterpret_cast<Data *>(raw);
    return (ret_ptr);
}