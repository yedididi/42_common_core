/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:02:14 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 13:01:10 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

void	draw(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				cub3d->info->img->data[y * WIDTH + x] = cub3d->ceiling;
			else
				cub3d->info->img->data[y * WIDTH + x] = cub3d->floor;
			if (cub3d->info->buf[y][x] != 0)
				cub3d->info->img->data[y * WIDTH + x] = cub3d->info->buf[y][x];
			x++;
		}
		y++;
	}
	print_minimap(cub3d);
	mlx_put_image_to_window(cub3d->mlx->mlx_ptr, cub3d->mlx->win_ptr,
		cub3d->info->img->img_ptr, 0, 0);
	draw_player(cub3d);
}

void	calc(t_cub3d *cub3d)
{
	t_dda	dda;
	t_info	*info;
	int		x;

	info = cub3d->info;
	x = 0;
	while (x < WIDTH)
	{
		basic_calculation(cub3d, &dda, x);
		help_get_texture(cub3d, &dda);
		dda.wall_x -= floor(dda.wall_x);
		fill_buffer(cub3d, &dda, x);
		x++;
	}
}

int	main_loop(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			cub3d->info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	calc(cub3d);
	draw(cub3d);
	return (0);
}

int	key_press(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
		press_w(cub3d->map, cub3d->info);
	else if (key == KEY_S)
		press_s(cub3d->map, cub3d->info);
	else if (key == KEY_D)
		press_d(cub3d->map, cub3d->info);
	else if (key == KEY_A)
		press_a(cub3d->map, cub3d->info);
	else if (key == KEY_LEFT)
		key_left(key, cub3d);
	else if (key == KEY_RIGHT)
		key_right(key, cub3d);
	else if (key == KEY_ESC)
		key_press_cross(cub3d);
	return (0);
}

void	start_game(t_cub3d *cub3d)
{
	cub3d->mlx->mlx_ptr = mlx_init();
	cub3d->mlx->win_ptr = mlx_new_window(cub3d->mlx->mlx_ptr,
			WIDTH, HEIGHT, "mlx");
	cub3d->info->img->img_ptr = mlx_new_image(cub3d->mlx->mlx_ptr,
			WIDTH, HEIGHT);
	cub3d->info->img->data = (int *)mlx_get_data_addr
		(cub3d->info->img->img_ptr, &cub3d->info->img->bpp,
			&cub3d->info->img->size_l, &cub3d->info->img->endian);
	init_texture(cub3d);
	mlx_loop_hook(cub3d->mlx->mlx_ptr, main_loop, cub3d);
	mlx_hook(cub3d->mlx->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, cub3d);
	mlx_hook(cub3d->mlx->win_ptr, X_EVENT_KEY_EXIT, 0, key_press_cross, cub3d);
	mlx_loop(cub3d->mlx->mlx_ptr);
}
