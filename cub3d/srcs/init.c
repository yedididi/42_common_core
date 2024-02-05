/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:37:58 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 14:27:26 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

char	*check_file_name(char *file_name, t_cub3d *cub3d)
{
	int	len;

	len = ft_strlen(file_name);
	if (ft_strncmp(file_name + (ft_strlen(file_name) - 4), ".cub", 4) == 0)
		return (file_name);
	else
		free_and_exit("incorrect file name\n", cub3d);
	return (0);
}

void	init(t_cub3d *cub3d, char *file_name)
{
	cub3d->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	cub3d->mlx->mlx_ptr = NULL;
	cub3d->mlx->win_ptr = NULL;
	cub3d->mlx->img_ptr = NULL;
	cub3d->info = NULL;
	cub3d->file_name = NULL;
	cub3d->blank = 0;
	cub3d->map = NULL;
	cub3d->row_size = 0;
	cub3d->col_size = 0;
	cub3d->no_path = NULL;
	cub3d->so_path = NULL;
	cub3d->we_path = NULL;
	cub3d->ea_path = NULL;
	cub3d->player = 0;
	cub3d->player_row = 0;
	cub3d->player_col = 0;
	cub3d->player_dir = 0;
	cub3d->floor = 0;
	cub3d->ceiling = 0;
	cub3d->texture_file = NULL;
	init_other(cub3d, file_name);
}

void	check_all_info_filled(t_cub3d *cub3d)
{
	if (cub3d->row_size > (HEIGHT / 10) - 10 || \
	cub3d->col_size > (WIDTH / 10) - 10)
		free_and_exit("map is too big\n", cub3d);
	if (cub3d->map == NULL || cub3d->contents == 0 || cub3d->player == 0)
		free_and_exit("not enough information\n", cub3d);
	cub3d->info = (t_info *)malloc(sizeof(t_info));
	if (cub3d->info == NULL)
		free_and_exit("malloc fail\n", cub3d);
	cub3d->info->img = (t_img *)malloc(sizeof(t_img));
	if (cub3d->info->img == NULL)
		free_and_exit("malloc fail\n", cub3d);
	cub3d->info->texture = NULL;
	cub3d->info->player_col = 0.0;
	cub3d->info->player_row = 0.0;
	init_info(cub3d);
}

void	init_info(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	cub3d->info->pos_x = (double)cub3d->player_col + 0.4;
	cub3d->info->pos_y = (double)cub3d->player_row + 0.4;
	init_dir(cub3d);
	cub3d->info->move_speed = 0.05;
	cub3d->info->rot_speed = 0.05;
	cub3d->info->re_buf = 0;
	cub3d->info->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	while (cub3d->info->buf && i < HEIGHT)
	{
		j = 0;
		cub3d->info->buf[i] = (int *)malloc(sizeof(int) * WIDTH);
		while (cub3d->info->buf[i] && j < WIDTH)
		{
			cub3d->info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_texture(t_cub3d *cub3d)
{
	int		i;
	char	*path;

	cub3d->info->texture = (int **)malloc(sizeof(int *) * 4);
	if (cub3d->info->texture == NULL)
		free_and_exit("malloc fail\n", cub3d);
	i = 0;
	cub3d->texture_file = (t_img *)malloc(sizeof(t_img) * 4);
	if (cub3d->texture_file == NULL)
		free_and_exit("malloc fail\n", cub3d);
	while (i < 4)
	{
		if (i == 0)
			path = cub3d->no_path;
		else if (i == 1)
			path = cub3d->so_path;
		else if (i == 2)
			path = cub3d->ea_path;
		else if (i == 3)
			path = cub3d->we_path;
		cub3d->info->texture[i] = open_texture(cub3d, i, path);
		i++;
	}
}
