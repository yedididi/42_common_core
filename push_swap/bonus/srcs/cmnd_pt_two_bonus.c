/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmnd_pt_two_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:09:28 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/28 15:11:49 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

int	execute_ra(t_info *info)
{
	t_node	*tmp_node;

	if (info->size_a == 0)
		return (6);
	tmp_node = info->head_a->rlink;
	info->head_a->rlink = info->head_a->rlink->rlink;
	tmp_node->rlink = info->tail_a;
	tmp_node->llink = info->tail_a->llink;
	info->head_a->rlink->llink = info->head_a;
	info->tail_a->llink->rlink = tmp_node;
	info->tail_a->llink = tmp_node;
	return (6);
}

int	execute_rb(t_info *info)
{
	t_node	*tmp_node;

	if (info->size_b == 0)
		return (6);
	tmp_node = info->head_b->rlink;
	info->head_b->rlink = info->head_b->rlink->rlink;
	tmp_node->rlink = info->tail_b;
	tmp_node->llink = info->tail_b->llink;
	info->head_b->rlink->llink = info->head_b;
	info->tail_b->llink->rlink = tmp_node;
	info->tail_b->llink = tmp_node;
	return (7);
}

int	execute_rr(t_info *info)
{
	execute_ra(info);
	execute_rb(info);
	return (8);
}

int	execute_rra(t_info *info)
{
	t_node	*tmp_node;

	if (info->size_a == 0)
		return (6);
	tmp_node = info->tail_a->llink;
	info->tail_a->llink = info->tail_a->llink->llink;
	tmp_node->rlink = info->head_a->rlink;
	tmp_node->llink = info->head_a;
	info->tail_a->llink->rlink = info->tail_a;
	info->head_a->rlink->llink = tmp_node;
	info->head_a->rlink = tmp_node;
	return (9);
}

int	execute_rrb(t_info *info)
{
	t_node	*tmp_node;

	if (info->size_b == 0)
		return (6);
	tmp_node = info->tail_b->llink;
	info->tail_b->llink = info->tail_b->llink->llink;
	tmp_node->rlink = info->head_b->rlink;
	tmp_node->llink = info->head_b;
	info->tail_b->llink->rlink = info->tail_b;
	info->head_b->rlink->llink = tmp_node;
	info->head_b->rlink = tmp_node;
	return (10);
}
