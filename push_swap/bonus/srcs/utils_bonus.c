/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:35:45 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/28 15:15:40 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

void	free_two_dim_arr(char **str)
{
	char	**tmp;

	tmp = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(tmp);
}

void	free_stack_ab(t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (node)
	{
		tmp = node->rlink;
		free(node);
		node = tmp;
	}
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
