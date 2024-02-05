/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:59:09 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/24 14:30:53 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	rra(t_info *info)
{
	t_node	*tmp_node;

	tmp_node = info->tail_a->llink;
	info->tail_a->llink = info->tail_a->llink->llink;
	tmp_node->rlink = info->head_a->rlink;
	tmp_node->llink = info->head_a;
	info->tail_a->llink->rlink = info->tail_a;
	info->head_a->rlink->llink = tmp_node;
	info->head_a->rlink = tmp_node;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_node	*tmp_node;

	tmp_node = info->tail_b->llink;
	info->tail_b->llink = info->tail_b->llink->llink;
	tmp_node->rlink = info->head_b->rlink;
	tmp_node->llink = info->head_b;
	info->tail_b->llink->rlink = info->tail_b;
	info->head_b->rlink->llink = tmp_node;
	info->head_b->rlink = tmp_node;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_node	*tmp_node;

	tmp_node = info->tail_a->llink;
	info->tail_a->llink = info->tail_a->llink->llink;
	tmp_node->rlink = info->head_a->rlink;
	tmp_node->llink = info->head_a;
	info->tail_a->llink->rlink = info->tail_a;
	info->head_a->rlink->llink = tmp_node;
	info->head_a->rlink = tmp_node;
	tmp_node = info->tail_b->llink;
	info->tail_b->llink = info->tail_b->llink->llink;
	tmp_node->rlink = info->head_b->rlink;
	tmp_node->llink = info->head_b;
	info->tail_b->llink->rlink = info->tail_b;
	info->head_b->rlink->llink = tmp_node;
	info->head_b->rlink = tmp_node;
	write(1, "rrr\n", 4);
}
