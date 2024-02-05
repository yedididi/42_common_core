/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:10:14 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 09:59:29 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	blank_flag(t_cub3d *cub3d)
{
	if (cub3d->blank == 0)
	{
		if (cub3d->row_size > 1)
			cub3d->blank = 1;
	}
	return ;
}

void	check_another_map(t_cub3d *cub3d)
{
	if (cub3d->blank == 1)
		free_and_exit("another map or last content is not a map.\n", cub3d);
	return ;
}

void	set_player_info(t_cub3d *cub3d, char player_dir, int col_size)
{
	cub3d->player = player_dir;
	cub3d->player_dir = player_dir;
	cub3d->player_row = cub3d->row_size;
	cub3d->player_col = col_size;
}

int	check_same_color(t_cub3d *cub3d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 3)
	{
		if (cub3d->f_color[i] == cub3d->c_color[i])
			count++;
		i++;
	}
	if (count == i)
		return (1);
	return (0);
}
