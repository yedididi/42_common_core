/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:38:13 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/24 14:30:12 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->head_a->rlink->data;
	info->head_a->rlink->data = info->head_a->rlink->rlink->data;
	info->head_a->rlink->rlink->data = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->head_b->rlink->data;
	info->head_b->rlink->data = info->head_b->rlink->rlink->data;
	info->head_b->rlink->rlink->data = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	int	tmp;

	if ((info->size_a < 2) || (info->size_b < 2))
		return ;
	tmp = info->head_a->rlink->data;
	info->head_a->rlink->data = info->head_a->rlink->rlink->data;
	info->head_a->rlink->rlink->data = tmp;
	tmp = info->head_b->rlink->data;
	info->head_b->rlink->data = info->head_b->rlink->rlink->data;
	info->head_b->rlink->rlink->data = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_info *info)
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
		free_node(newnode);
		info->size_a++;
		info->size_b--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_info *info)
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
		free_node(newnode);
		info->size_a--;
		info->size_b++;
		write(1, "pb\n", 3);
	}
}
