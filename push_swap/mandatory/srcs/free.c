/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:30:02 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/27 14:01:45 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	free_two_dim_arr(char **str)
{
	char	**tmp;

	tmp = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(tmp);
}

void	free_stack_ab(t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (node)
	{
		tmp = node->rlink;
		free(node);
		node = tmp;
	}
}

void	free_node(t_node *node)
{
	free(node);
}
