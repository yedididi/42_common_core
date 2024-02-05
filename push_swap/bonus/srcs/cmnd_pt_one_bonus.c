/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmnd_pt_one_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:42:43 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/25 15:56:14 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

int	execute_sa(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return (1);
	tmp = info->head_a->rlink->data;
	info->head_a->rlink->data = info->head_a->rlink->rlink->data;
	info->head_a->rlink->rlink->data = tmp;
	return (1);
}

int	execute_sb(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return (2);
	tmp = info->head_b->rlink->data;
	info->head_b->rlink->data = info->head_b->rlink->rlink->data;
	info->head_b->rlink->rlink->data = tmp;
	return (2);
}

int	execute_ss(t_info *info)
{
	execute_sa(info);
	execute_sb(info);
	return (3);
}

int	execute_pa(t_info *info)
{
	t_node	*newnode;

	if (info->head_b->rlink != info->tail_b)
	{
		newnode = create_newnode(info->head_b->rlink->data);
		newnode->llink = info->head_a;
		newnode->rlink = info->head_a->rlink;
		info->head_a->rlink->llink = newnode;
		info->head_a->rlink = newnode;
		newnode = info->head_b->rlink;
		newnode->rlink->llink = info->head_b;
		info->head_b->rlink = newnode->rlink;
		info->size_a++;
		info->size_b--;
	}
	return (4);
}

int	execute_pb(t_info *info)
{
	t_node	*newnode;

	if (info->head_a->rlink != info->tail_a)
	{
		newnode = create_newnode(info->head_a->rlink->data);
		newnode->llink = info->head_b;
		newnode->rlink = info->head_b->rlink;
		info->head_b->rlink->llink = newnode;
		info->head_b->rlink = newnode;
		newnode = info->head_a->rlink;
		newnode->rlink->llink = info->head_a;
		info->head_a->rlink = newnode->rlink;
		info->size_a--;
		info->size_b++;
	}
	return (5);
}
