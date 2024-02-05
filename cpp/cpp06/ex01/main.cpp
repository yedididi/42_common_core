/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:00:06 by yejlee2           #+#    #+#             */
/*   Updated: 2024/01/05 10:37:04 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data    test_data;
    uintptr_t     tmp;

    tmp = Serializer::serialize(&test_data);
    printf("test data's address   is:%p\n", &test_data);
    printf("result of deserialize is:%p\n", Serializer::deserialize(tmp));
    if (Serializer::deserialize(tmp) == &test_data)
        std::cout << "ok" << std::endl;
    else
        std::cout << "ko" << std::endl;
    return (0);
}