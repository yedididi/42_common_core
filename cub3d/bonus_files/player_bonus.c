/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:53:20 by misukim           #+#    #+#             */
/*   Updated: 2023/12/01 14:44:12 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

void	draw_player(t_cub3d *cub3d)
{
	double	x;
	double	y;
	int		center_x;
	int		center_y;

	y = cub3d->info->pos_x;
	x = cub3d->info->pos_y;
	center_x = (int)(y * MINIMAP_SIZE);
	center_y = (int)(x * MINIMAP_SIZE);
	while (y < cub3d->info->pos_x + 0.2)
	{
		x = cub3d->info->pos_y;
		while (x < cub3d->info->pos_y + 0.1)
		{
			mlx_pixel_put(cub3d->mlx->mlx_ptr, cub3d->mlx->win_ptr,
				(int)(y * MINIMAP_SIZE), (int)(x * MINIMAP_SIZE), 0xE4181B);
			x += 0.01;
		}
		y += 0.01;
	}
}
