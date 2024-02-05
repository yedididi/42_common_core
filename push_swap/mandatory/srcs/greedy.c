/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:29:57 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/24 14:34:53 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	be_greedy(t_info *info)
{
	int	mvcount_a;
	int	mvcount_b;

	while (info->size_b)
	{
		mvcount_a = 0;
		mvcount_b = 0;
		calculate_mv(&mvcount_a, &mvcount_b, info);
		rotate_both(&mvcount_a, &mvcount_b, info);
		rotate_a(mvcount_a, info);
		rotate_b(mvcount_b, info);
		pa(info);
	}
	last_rotate(info);
}

void	rotate_both(int *mvcount_a, int *mvcount_b, t_info *info)
{
	while (*mvcount_a && *mvcount_b && (*mvcount_a > 0 && *mvcount_b > 0))
	{
		rr(info);
		*mvcount_a = *mvcount_a - 1;
		*mvcount_b = *mvcount_b - 1;
	}
	while (*mvcount_a && *mvcount_b && (*mvcount_a < 0 && *mvcount_b < 0))
	{
		rrr(info);
		*mvcount_a = *mvcount_a + 1;
		*mvcount_b = *mvcount_b + 1;
	}
}

void	rotate_a(int mvcount_a, t_info *info)
{
	while (mvcount_a)
	{
		if (mvcount_a > 0)
		{
			ra(info);
			mvcount_a = mvcount_a - 1;
		}
		else
		{
			rra(info);
			mvcount_a = mvcount_a + 1;
		}
	}
}

void	rotate_b(int mvcount_b, t_info *info)
{
	while (mvcount_b)
	{
		if (mvcount_b > 0)
		{
			rb(info);
			mvcount_b = mvcount_b - 1;
		}
		else
		{
			rrb(info);
			mvcount_b = mvcount_b + 1;
		}
	}
}

void	last_rotate(t_info *info)
{
	int	min_location;

	min_location = calculate_mv_min(info);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(info);
			min_location--;
		}
		else
		{
			rra(info);
			min_location++;
		}
	}
}
