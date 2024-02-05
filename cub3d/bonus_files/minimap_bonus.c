/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:08:02 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 13:01:39 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

void	make_white_block(t_cub3d *cub3d, int y, int x)
{
	int	i;
	int	j;
	int	color_tmp;
	int	pixel_pos;

	j = 0;
	i = x * MINIMAP_SIZE;
	color_tmp = 0xFFFFFF;
	while (i < (x + 1) * MINIMAP_SIZE)
	{
		j = y * MINIMAP_SIZE;
		while (j < (y + 1) * MINIMAP_SIZE)
		{
			if ((j == ((y + 1) * MINIMAP_SIZE) - 1) || (j == y * MINIMAP_SIZE)
				|| (i == ((x + 1) * MINIMAP_SIZE) - 1))
				color_tmp = 0xFFFFFF;
			else
				color_tmp = 0xFFFFFF;
			pixel_pos = (j * WIDTH) + i;
			cub3d->info->img->data[pixel_pos] = color_tmp;
			j++;
		}
		i++;
	}
}

void	make_black_block(t_cub3d *cub3d, int y, int x)
{
	int	i;
	int	j;
	int	color_tmp;
	int	pixel_pos;

	j = 0;
	i = x * MINIMAP_SIZE;
	color_tmp = 0x000000;
	while (i < (x + 1) * MINIMAP_SIZE)
	{
		j = y * MINIMAP_SIZE;
		while (j < (y + 1) * MINIMAP_SIZE)
		{
			if ((j == ((y + 1) * MINIMAP_SIZE) - 1) || (j == y * MINIMAP_SIZE)
				|| (i == ((x + 1) * MINIMAP_SIZE) - 1))
				color_tmp = 0x000000;
			else
				color_tmp = 0x000000;
			pixel_pos = (j * WIDTH) + i;
			cub3d->info->img->data[pixel_pos] = color_tmp;
			j++;
		}
		i++;
	}
}

void	print_minimap(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < cub3d->row_size)
	{
		y = 0;
		while (y < cub3d->col_size)
		{
			if (cub3d->map[x] == 0 || cub3d->map[x][y] == 0)
				break ;
			if (cub3d->map[x][y] == '1')
				make_black_block(cub3d, x, y);
			if (cub3d->map[x][y] == '0' || cub3d->map[x][y] == 'N'
				|| cub3d->map[x][y] == 'S' || cub3d->map[x][y] == 'W'
					|| cub3d->map[x][y] == 'E')
				make_white_block(cub3d, x, y);
			y++;
		}
		x++;
	}
}
