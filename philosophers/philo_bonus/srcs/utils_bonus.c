/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:31:08 by yejlee2           #+#    #+#             */
/*   Updated: 2023/07/20 13:51:38 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

const char	*before_atoi(const char *str)
{
	if ((*str == '-') || (*str == '+'))
	{
		str++;
		if (ft_isnum(*str) == 0)
			return (NULL);
	}
	if (ft_strlen(str) > 11)
		return (NULL);
	return (str);
}

long long	ft_atoi(const char *str)
{
	long long	minus;
	long long	number;

	number = 0;
	minus = 1;
	while (((*str >= 9) && (*str <= 13)) || *str == 32)
		str++;
	if (*str == '-')
		minus = -1;
	str = before_atoi(str);
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (ft_isnum(*str))
			number = (number * 10) + (*str - '0');
		else
			return (-1);
		str++;
	}
	return (minus * number);
}

int	ft_isnum(int num)
{
	if ((num >= '0') && (num <= '9'))
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
