/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:08:37 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 14:50:04 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

void	free_info_and_other(t_cub3d *cub3d)
{
	if (cub3d->no_path)
		free(cub3d->no_path);
	if (cub3d->so_path)
		free(cub3d->so_path);
	if (cub3d->we_path)
		free(cub3d->we_path);
	if (cub3d->ea_path)
		free(cub3d->ea_path);
	if (cub3d->texture_file)
		free(cub3d->texture_file);
	if (cub3d->info && cub3d->info->buf)
		free(cub3d->info->buf);
	if (cub3d->info && cub3d->info->img)
		free(cub3d->info->img);
	if (cub3d->info && cub3d->info->texture)
		free(cub3d->info->texture);
	if (cub3d->info)
		free(cub3d->info);
	if (cub3d->mlx)
		free(cub3d->mlx);
}

void	free_only(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map && cub3d->map[i])
	{
		free(cub3d->map[i]);
		i++;
	}
	if (cub3d->map)
		free(cub3d->map);
	i = 0;
	while (i < HEIGHT)
	{
		if (cub3d->info && cub3d->info->buf && cub3d->info->buf[i])
			free(cub3d->info->buf[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (cub3d->info && cub3d->info->texture[i])
			free(cub3d->info->texture[i]);
		i++;
	}
	free_info_and_other(cub3d);
}

void	free_and_exit(char *str, t_cub3d *cub3d)
{
	printf("Error\n");
	printf("%s", str);
	if (ft_strncmp(str, "No input file.\n", 15) == 0)
		exit(1);
	free_only(cub3d);
	exit(1);
}
