/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:42:54 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 13:01:20 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

void	get_sidedist(t_dda *dda, t_info *info)
{
	if (dda->raydirx < 0)
	{
		dda->step_x = -1;
		dda->sidedistx = (info->pos_x - dda->map_x) * dda->deltadistx;
	}
	else
	{
		dda->step_x = 1;
		dda->sidedistx = (dda->map_x + 1.0 - info->pos_x) * dda->deltadistx;
	}
	if (dda->raydiry < 0)
	{
		dda->step_y = -1;
		dda->sidedisty = (info->pos_y - dda->map_y) * dda->deltadisty;
	}
	else
	{
		dda->step_y = 1;
		dda->sidedisty = (dda->map_y + 1.0 - info->pos_y) * dda->deltadisty;
	}
}

void	init_dda(t_cub3d *cub3d, t_dda *dda, int x)
{
	dda->camera_x = 2 * x / (double)WIDTH - 1;
	dda->raydirx = cub3d->info->dir_x + cub3d->info->plane_x * dda->camera_x;
	dda->raydiry = cub3d->info->dir_y + cub3d->info->plane_y * dda->camera_x;
	dda->map_x = (int)cub3d->info->pos_x;
	dda->map_y = (int)cub3d->info->pos_y;
	dda->deltadistx = fabs(1 / dda->raydirx);
	dda->deltadisty = fabs(1 / dda->raydiry);
	dda->hit = 0;
}

void	basic_calculation(t_cub3d *cub3d, t_dda *dda, int x)
{
	init_dda(cub3d, dda, x);
	get_sidedist(dda, cub3d->info);
	while (dda->hit == 0)
	{
		if (dda->sidedistx < dda->sidedisty)
		{
			dda->sidedistx += dda->deltadistx;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->sidedisty += dda->deltadisty;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (cub3d->map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
}

void	help_get_texture(t_cub3d *cub3d, t_dda *dda)
{
	t_info	*info;

	info = cub3d->info;
	if (dda->side == 0)
	{
		dda->perpwalldist = (dda->map_x - info->pos_x + (1 - dda->step_x) / 2)
			/ dda->raydirx;
	}
	else
	{
		dda->perpwalldist = (dda->map_y - info->pos_y + (1 - dda->step_y) / 2)
			/ dda->raydiry;
	}
	dda->lineheight = (int)(HEIGHT / dda->perpwalldist);
	dda->drawstart = -dda->lineheight / 2 + HEIGHT / 2;
	if (dda->drawstart < 0)
		dda->drawstart = 0;
	dda->drawend = dda->lineheight / 2 + HEIGHT / 2;
	if (dda->drawend >= HEIGHT)
		dda->drawend = HEIGHT - 1;
	dda->texnum = get_texnum(cub3d, dda);
	if (dda->side == 0)
		dda->wall_x = info->pos_y + dda->perpwalldist * dda->raydiry;
	else
		dda->wall_x = info->pos_x + dda->perpwalldist * dda->raydirx;
}

void	fill_buffer(t_cub3d *cub3d, t_dda *dda, int x)
{
	t_info	*info;

	info = cub3d->info;
	dda->tex_x = (int)(dda->wall_x * (double)cub3d->texture_file
		[dda->texnum].size_w);
	if ((dda->side == 0 && dda->raydirx < 0)
		|| (dda->side == 1 && dda->raydiry > 0))
		dda->tex_x = cub3d->texture_file[dda->texnum].size_w - dda->tex_x - 1;
	dda->step = 1.0 * cub3d->texture_file[dda->texnum].size_h / dda->lineheight;
	dda->tex_pos = (dda->drawstart - HEIGHT / 2 + dda->lineheight / 2)
		* dda->step;
	dda->y = dda->drawstart;
	while (dda->y < dda->drawend)
	{
		dda->tex_y = (int)dda->tex_pos
			& (cub3d->texture_file[dda->texnum].size_h - 1);
		dda->tex_pos += dda->step;
		dda->color = info->texture[dda->texnum]
		[cub3d->texture_file[dda->texnum].size_w * dda->tex_y + dda->tex_x];
		if (dda->side == 1)
			dda->color = (dda->color >> 1) & 8355711;
		info->buf[dda->y][x] = dda->color;
		info->re_buf = 1;
		dda->y++;
	}
}
