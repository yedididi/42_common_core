/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:09:01 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/27 14:21:18 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	error(int c)
{
	if (c == 'y')
		write(2, "Error\n", 6);
	else if (c == 'n')
		exit(0);
	exit(1);
}

const char	*before_atoi(const char *str)
{
	if ((*str == '-') || (*str == '+'))
	{
		str++;
		if (ft_isnum(*str) == 0)
			error('y');
	}
	if (ft_strlen(str) > 11)
		error('y');
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
	while (*str)
	{
		if (ft_isnum(*str))
			number = (number * 10) + (*str - '0');
		else
			error('y');
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
