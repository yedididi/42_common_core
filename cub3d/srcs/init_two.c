/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:50:53 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/03 16:07:30 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	init_other(t_cub3d *cub3d, char *file_name)
{
	int	i;

	i = 0;
	while (3 > i)
	{
		cub3d->f_color[i] = -1;
		cub3d->c_color[i] = -1;
		i++;
	}
	cub3d->contents = 0;
	cub3d->player = 0;
	cub3d->player_row = 0;
	cub3d->player_col = 0;
	cub3d->ceiling = 0;
	cub3d->floor = 0;
	cub3d->file_name = check_file_name(file_name, cub3d);
}

void	init_dir_two(t_cub3d *cub3d)
{
	if (cub3d->player_dir == 'W')
	{
		cub3d->info->dir_x = -1.0;
		cub3d->info->dir_y = 0.0;
		cub3d->info->plane_x = 0.0;
		cub3d->info->plane_y = 0.66; // -0.66
	}
	else if (cub3d->player_dir == 'E')
	{
		cub3d->info->dir_x = 1.0;
		cub3d->info->dir_y = 0.0;
		cub3d->info->plane_x = 0;
		cub3d->info->plane_y = -0.66; // 0.66
	}
}

void	init_dir(t_cub3d *cub3d)
{
	if (cub3d->player_dir == 'N')
	{
		cub3d->info->dir_x = 0.0;
		cub3d->info->dir_y = 1.0; // -1.0
		cub3d->info->plane_x = 0.66;
		cub3d->info->plane_y = 0.0;
	}
	else if (cub3d->player_dir == 'S')
	{
		cub3d->info->dir_x = 0.0;
		cub3d->info->dir_y = -1.0; // 1.0
		cub3d->info->plane_x = -0.66;
		cub3d->info->plane_y = 0.0;
	}
	init_dir_two(cub3d);
}
