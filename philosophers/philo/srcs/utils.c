/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:31:08 by yejlee2           #+#    #+#             */
/*   Updated: 2023/07/19 14:01:13 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

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

uint64_t	ft_get_time(void)
{
	uint64_t		return_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (return_time);
}
