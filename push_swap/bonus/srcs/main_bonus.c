/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:11:47 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/28 15:15:23 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 1)
		error('n');
	init_list(&info);
	fill_stack(argc, argv, &info);
	execute(&info);
	if (check(&info) == 0)
		write(1, "KO\n", 3);
	else if (check(&info) == 1)
		write(1, "OK\n", 3);
	free_stack_ab(info.head_a);
	free_stack_ab(info.head_b);
	exit(0);
}

void	error(int num)
{
	if (num == 'y')
		write(2, "Error\n", 6);
	exit(1);
}

int	check(t_info *info)
{
	int		i;
	t_node	*node;

	i = 0;
	node = info->head_a->rlink;
	if (info->size_b != 0)
		return (0);
	while (info->size_a - 1 > i)
	{
		if (node->data > node->rlink->data)
			return (0);
		node = node->rlink;
		i++;
	}
	return (1);
}
