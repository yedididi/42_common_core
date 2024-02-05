/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:14:38 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 16:04:41 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		free_and_exit("No input file.\n", &cub3d);
	init(&cub3d, argv[1]);
	get_size(&cub3d);
	parse_file(&cub3d);
	wall_check(&cub3d);
	check_all_info_filled(&cub3d);
	start_game(&cub3d);
	free_only(&cub3d);
	return (0);
}
