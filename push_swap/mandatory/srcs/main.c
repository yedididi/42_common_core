/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:58:38 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/27 14:49:02 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 1)
		error('n');
	init_list(&info);
	fill_stack(argc, argv, &info);
	get_pivot(&info);
	start_sorting(&info);
	exit(0);
}
