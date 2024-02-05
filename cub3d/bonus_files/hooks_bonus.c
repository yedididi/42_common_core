/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:21:38 by misukim           #+#    #+#             */
/*   Updated: 2023/12/01 11:37:14 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	key_press_cross(t_cub3d *cub3d)
{
	if (cub3d->mlx->img_ptr)
		mlx_destroy_image(cub3d->mlx->mlx_ptr, cub3d->mlx->img_ptr);
	if (cub3d->mlx->win_ptr)
		mlx_destroy_window(cub3d->mlx->mlx_ptr, cub3d->mlx->win_ptr);
	free_only(cub3d);
	exit(0);
	return (0);
}

void	press_w(char **worldmap, t_info *info)
{
	double	border;
	double	next_y;
	double	next_x;

	border = 0.2;
	next_y = info->pos_y + info->dir_y * info->move_speed;
	next_x = info->pos_x + info->dir_x * info->move_speed;
	if (worldmap[(int)next_y][(int)next_x] != '1' && \
	worldmap[(int)(next_y - border)][(int)next_x] != '1' && \
	worldmap[(int)(next_y + border)][(int)next_x] != '1' && \
	worldmap[(int)next_y][(int)(next_x - border)] != '1' && \
	worldmap[(int)next_y][(int)(next_x + border)] != '1')
	{
		info->pos_y += info->dir_y * info->move_speed;
		info->pos_x += info->dir_x * info->move_speed;
	}
}

void	press_s(char **worldmap, t_info *info)
{
	double	border;
	double	next_y;
	double	next_x;

	border = 0.2;
	next_y = info->pos_y - info->dir_y * info->move_speed;
	next_x = info->pos_x - info->dir_x * info->move_speed;
	if (worldmap[(int)next_y][(int)next_x] != '1' && \
	worldmap[(int)(next_y - border)][(int)next_x] != '1' && \
	worldmap[(int)(next_y + border)][(int)next_x] != '1' && \
	worldmap[(int)next_y][(int)(next_x - border)] != '1' && \
	worldmap[(int)next_y][(int)(next_x + border)] != '1')
	{
		info->pos_y -= info->dir_y * info->move_speed;
		info->pos_x -= info->dir_x * info->move_speed;
	}
}

void	press_a(char **worldmap, t_info *info)
{
	double	border;
	double	next_y;
	double	next_x;

	border = 0.2;
	next_y = info->pos_y - info->dir_x * info->move_speed;
	next_x = info->pos_x + info->dir_y * info->move_speed;
	if (worldmap[(int)next_y][(int)next_x] != '1' && \
	worldmap[(int)(next_y - border)][(int)next_x] != '1' && \
	worldmap[(int)(next_y + border)][(int)next_x] != '1' && \
	worldmap[(int)next_y][(int)(next_x - border)] != '1' && \
	worldmap[(int)next_y][(int)(next_x + border)] != '1')
	{
		info->pos_y -= info->dir_x * info->move_speed;
		info->pos_x += info->dir_y * info->move_speed;
	}
}

void	press_d(char **worldmap, t_info *info)
{
	double	border;
	double	next_y;
	double	next_x;

	border = 0.2;
	next_y = info->pos_y + info->dir_x * info->move_speed;
	next_x = info->pos_x - info->dir_y * info->move_speed;
	if (worldmap[(int)(next_y + border)][(int)info->pos_x] != '1' && \
	worldmap[(int)next_y][(int)info->pos_x] != '1')
		info->pos_y += info->dir_x * info->move_speed;
	if (worldmap[(int)next_y][(int)(next_x + border)] != '1' && \
	worldmap[(int)next_y][(int)next_x] != '1')
		info->pos_x -= info->dir_y * info->move_speed;
}
