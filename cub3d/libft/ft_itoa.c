/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:21:14 by misukim           #+#    #+#             */
/*   Updated: 2023/03/31 14:06:23 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	push_values(long long value, char *str)
{
	size_t	i;

	i = 0;
	if (value < 0)
	{
		value *= (-1);
		str[i] = '-';
		str[i + 1] = '\0';
	}
	if (value > 9)
		push_values(value / 10, str);
	while (str[i] != '\0')
		i++;
	str[i] = "0123456789"[value % 10];
	str[i + 1] = '\0';
}

static size_t	len_for_malloc(long long value)
{
	size_t	len;

	len = 0;
	if (value < 0)
	{
		value *= (-1);
		len++;
	}
	while (value >= 10)
	{
		value /= 10;
		len++;
	}
	len += 1;
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;

	len = len_for_malloc((long long)n);
	result = malloc(len + 1);
	if (!result)
		return (0);
	*result = 0;
	push_values((long long)n, result);
	result[len] = '\0';
	return (result);
}
