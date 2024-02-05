/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:04:58 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/27 13:12:46 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	init_list(t_info *info)
{
	info->head_a = (t_node *)malloc(sizeof(t_node));
	info->tail_a = (t_node *)malloc(sizeof(t_node));
	info->head_b = (t_node *)malloc(sizeof(t_node));
	info->tail_b = (t_node *)malloc(sizeof(t_node));
	if (info->head_b == 0 || info->tail_b == 0
		|| info->head_a == 0 || info->tail_a == 0)
		error('y');
	info->head_a->data = 0;
	info->tail_a->data = 0;
	info->head_a->llink = 0;
	info->head_a->rlink = info->tail_a;
	info->tail_a->llink = info->head_a;
	info->tail_a->rlink = 0;
	info->size_a = 0;
	info->head_b->data = 0;
	info->tail_b->data = 0;
	info->head_b->llink = 0;
	info->head_b->rlink = info->tail_b;
	info->tail_b->llink = info->head_b;
	info->tail_b->rlink = 0;
	info->size_b = 0;
	info->first_pivot = 0;
	info->second_pivot = 0;
}

t_node	*create_newnode(int value)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == 0)
		error('y');
	newnode->llink = 0;
	newnode->rlink = 0;
	newnode->data = value;
	return (newnode);
}

void	add_newnode(int value, t_info *info)
{
	t_node	*newnode;

	search_for_dup(value, *info);
	newnode = create_newnode(value);
	newnode->llink = info->tail_a->llink;
	info->tail_a->llink->rlink = newnode;
	info->tail_a->llink = newnode;
	newnode->rlink = info->tail_a;
	info->size_a++;
}

void	search_for_dup(int value, t_info info)
{
	int		i;
	t_node	*node;

	i = 0;
	node = info.head_a->rlink;
	while (info.size_a > i)
	{
		if (value == node->data)
			error('y');
		node = node->rlink;
		i++;
	}
}
