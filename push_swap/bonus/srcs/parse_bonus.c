/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:15:36 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/28 15:15:30 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

void	fill_stack(int argc, char *argv[], t_info *info)
{
	int			i;
	long long	num;

	i = 1;
	while (i < argc)
	{
		if (check_for_sp(argv[i]) == 1)
			fill_index_sp(argv[i], info);
		else
		{
			num = ft_atoi(argv[i]);
			if ((num < -2147483648) || (num > 2147483647))
				error('y');
			add_newnode((int)num, info);
		}
		i++;
	}
	if (check(info) == 1)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
}

int	check_for_sp(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

void	fill_index_sp(char *str, t_info *info)
{
	long long	num;
	char		**nums;
	char		**tmp;

	nums = ft_split(str, ' ');
	if (nums == 0)
		error('y');
	tmp = nums;
	while (*nums)
	{
		num = ft_atoi(*nums);
		if ((num < -2147483648) || (num > 2147483647))
			error('y');
		add_newnode((int)num, info);
		nums++;
	}
	free_two_dim_arr(tmp);
}
