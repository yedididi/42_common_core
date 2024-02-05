/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:41:21 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/24 14:34:22 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	calculate_mv(int *mvcount_a, int *mvcount_b, t_info *info)
{
	int		i;
	int		tmp_a;
	int		tmp_b;
	t_node	*node;

	i = 0;
	node = info->head_b->rlink;
	while (i < info->size_b)
	{
		tmp_a = calculate_mv_a(info, node);
		tmp_b = calculate_mv_b(info, i);
		if (i == 0 || compare(*mvcount_a, *mvcount_b, tmp_a, tmp_b))
		{
			*mvcount_a = tmp_a;
			*mvcount_b = tmp_b;
		}
		node = node->rlink;
		i++;
	}
}

int	calculate_mv_a(t_info *info, t_node *node)
{
	int	mvcount_a;

	if (node->data < min_value_of_a(info))
		mvcount_a = calculate_mv_min(info);
	else if (node->data > max_value_of_a(info))
		mvcount_a = calculate_mv_max(info);
	else
		mvcount_a = calculate_mv_rest(node->data, info);
	return (mvcount_a);
}

int	calculate_mv_b(t_info *info, int i)
{
	int	mvcount_b;

	if (i >= (info->size_b + 1) / 2)
		mvcount_b = (info->size_b - i) * (-1);
	else
		mvcount_b = i;
	return (mvcount_b);
}

int	min_value_of_a(t_info *info)
{
	int		i;
	int		min;
	t_node	*node;

	i = 0;
	node = info->head_a->rlink;
	min = node->data;
	while (i < info->size_a)
	{
		if (min > node->data)
			min = node->data;
		node = node->rlink;
		i++;
	}
	return (min);
}

int	max_value_of_a(t_info *info)
{
	int		i;
	int		max;
	t_node	*node;

	i = 0;
	node = info->head_a->rlink;
	max = node->data;
	while (i < info->size_a)
	{
		if (max < node->data)
			max = node->data;
		node = node->rlink;
		i++;
	}
	return (max);
}
