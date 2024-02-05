/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:57:18 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/24 14:34:44 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	calculate_mv_min(t_info *info)
{
	int		i;
	t_node	*node;

	i = 0;
	node = info->head_a->rlink;
	while (i < info->size_a)
	{
		if (node->data == min_value_of_a(info))
			break ;
		node = node->rlink;
		i++;
	}
	if (i >= (info->size_a + 1) / 2)
		i = (info->size_a - i) * (-1);
	return (i);
}

int	calculate_mv_max(t_info *info)
{
	int		i;
	t_node	*node;

	i = 0;
	node = info->head_a->rlink;
	while (i < info->size_a)
	{
		if (node->data == max_value_of_a(info))
			break ;
		node = node->rlink;
		i++;
	}
	i++;
	if (i >= (info->size_a + 1) / 2)
		i = (info->size_a - i) * (-1);
	return (i);
}

int	calculate_mv_rest(int num, t_info *info)
{
	t_node	*node;
	int		i;

	node = info->head_a->rlink;
	i = 1;
	if (num < info->head_a->rlink->data && num > info->tail_a->llink->data)
		return (0);
	while (node && node->rlink)
	{
		if (num > node->data && num < node->rlink->data)
			break ;
		node = node->rlink;
		i++;
	}
	if (i >= (info->size_a + 1) / 2)
		i = (info->size_a - i) * (-1);
	return (i);
}

int	compare(int mvcount_a, int mvcount_b, int tmp_a, int tmp_b)
{
	if (mvcount_a < 0)
		mvcount_a = mvcount_a * (-1);
	if (mvcount_b < 0)
		mvcount_b = mvcount_b * (-1);
	if (tmp_a < 0)
		tmp_a = tmp_a * (-1);
	if (tmp_b < 0)
		tmp_b = tmp_b * (-1);
	if (mvcount_a + mvcount_b > tmp_a + tmp_b)
		return (1);
	else
		return (0);
}
