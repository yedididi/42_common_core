/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:36:40 by misukim           #+#    #+#             */
/*   Updated: 2023/03/31 00:47:23 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	size_t				i;

	sign = 1;
	result = 0;
	i = ft_isspace(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= (-1);
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (sign > 0 && result > ULONG_MAX / 2)
			return ((int)(LLONG_MAX));
		else if (sign < 0 && result > ULONG_MAX / 2)
			return ((int)(LLONG_MIN));
		i++;
	}
	return ((int)(sign * result));
}
