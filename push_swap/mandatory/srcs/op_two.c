/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:57:31 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/24 14:31:21 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ra(t_info *info)
{
	t_node	*tmp_node;

	tmp_node = info->head_a->rlink;
	info->head_a->rlink = info->head_a->rlink->rlink;
	tmp_node->rlink = info->tail_a;
	tmp_node->llink = info->tail_a->llink;
	info->head_a->rlink->llink = info->head_a;
	info->tail_a->llink->rlink = tmp_node;
	info->tail_a->llink = tmp_node;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_node	*tmp_node;

	tmp_node = info->head_b->rlink;
	info->head_b->rlink = info->head_b->rlink->rlink;
	tmp_node->rlink = info->tail_b;
	tmp_node->llink = info->tail_b->llink;
	info->head_b->rlink->llink = info->head_b;
	info->tail_b->llink->rlink = tmp_node;
	info->tail_b->llink = tmp_node;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	t_node	*tmp_node;

	tmp_node = info->head_a->rlink;
	info->head_a->rlink = info->head_a->rlink->rlink;
	tmp_node->rlink = info->tail_a;
	tmp_node->llink = info->tail_a->llink;
	info->head_a->rlink->llink = info->head_a;
	info->tail_a->llink->rlink = tmp_node;
	info->tail_a->llink = tmp_node;
	tmp_node = info->head_b->rlink;
	info->head_b->rlink = info->head_b->rlink->rlink;
	tmp_node->rlink = info->tail_b;
	tmp_node->llink = info->tail_b->llink;
	info->head_b->rlink->llink = info->head_b;
	info->tail_b->llink->rlink = tmp_node;
	info->tail_b->llink = tmp_node;
	write(1, "rr\n", 3);
}
