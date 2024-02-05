/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:59:56 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/27 13:03:08 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	start_sorting(t_info *info)
{
	if (info->size_a == 2)
		sort_two_nbrs(info);
	else if (info->size_a == 3)
		sort_three_nbrs(info);
	else
		sort_more_nbrs(info);
}

void	sort_two_nbrs(t_info *info)
{
	if (info->head_a->rlink->data > info->head_a->rlink->rlink->data)
		sa(info);
}

void	sort_three_nbrs(t_info *info)
{
	int	head;
	int	body;
	int	tail;

	head = info->head_a->rlink->data;
	body = info->head_a->rlink->rlink->data;
	tail = info->head_a->rlink->rlink->rlink->data;
	if (body > head && body > tail && tail > head)
	{
		sa(info);
		ra(info);
	}
	else if (head > body && tail > body && tail > head)
		sa(info);
	else if (body > head && body > tail && head > tail)
		rra(info);
	else if (head > body && tail > body && head > tail)
		ra(info);
	else if (head > body && body > tail && head > tail)
	{
		sa(info);
		rra(info);
	}
}

void	sort_more_nbrs(t_info *info)
{
	make_three_parts(info);
	while (info->size_a > 3)
		pb(info);
	if (info->size_a == 2)
		sort_two_nbrs(info);
	else if (info->size_a == 3)
		sort_three_nbrs(info);
	be_greedy(info);
	free_stack_ab(info->head_a);
	free_stack_ab(info->head_b);
}

void	make_three_parts(t_info *info)
{
	int	size;

	size = info->size_a;
	while (size)
	{
		if (info->head_a->rlink->data < info->first_pivot)
		{
			pb(info);
			rb(info);
		}
		else if (info->head_a->rlink->data < info->second_pivot)
			pb(info);
		else
			ra(info);
		size--;
	}
}
