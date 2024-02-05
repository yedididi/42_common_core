/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:22:21 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 13:01:42 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

void	key_left(int keycode, t_cub3d *cub3d)
{
	t_info	*info;
	double	old_dir_x;
	double	old_plane_x;

	info = cub3d->info;
	if (keycode == KEY_LEFT)
	{
		old_dir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed)
			- info->dir_y * sin(-info->rot_speed);
		info->dir_y = old_dir_x * sin(-info->rot_speed)
			+ info->dir_y * cos(-info->rot_speed);
		old_plane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed)
			- info->plane_y * sin(-info->rot_speed);
		info->plane_y = old_plane_x * sin(-info->rot_speed)
			+ info->plane_y * cos(-info->rot_speed);
	}
}

void	key_right(int keycode, t_cub3d *cub3d)
{
	t_info	*info;
	double	old_dir_x;
	double	old_plane_x;

	info = cub3d->info;
	if (keycode == KEY_RIGHT)
	{
		old_dir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed)
			- info->dir_y * sin(info->rot_speed);
		info->dir_y = old_dir_x * sin(info->rot_speed)
			+ info->dir_y * cos(info->rot_speed);
		old_plane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed)
			- info->plane_y * sin(info->rot_speed);
		info->plane_y = old_plane_x * sin(info->rot_speed)
			+ info->plane_y * cos(info->rot_speed);
	}
}
