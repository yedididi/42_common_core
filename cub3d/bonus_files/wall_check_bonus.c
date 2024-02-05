/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:11:02 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 15:39:50 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

void	wall_check(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 1;
	if (cub3d->map == NULL || cub3d->map[0] == NULL)
		free_and_exit("no map\n", cub3d);
	check_first_and_last(cub3d);
	while (cub3d->row_size > i)
	{
		j = 0;
		check_wasd(cub3d, i, j);
		i++;
	}
}

void	check_wasd(t_cub3d *cub3d, int i, int j)
{
	while (cub3d->map[i][j] == ' ' || cub3d->map[i][j] == '\t')
		j++;
	if (cub3d->map[i][j++] != '1')
		free_and_exit("[1]not surrounded by walls\n", cub3d);
	while (cub3d->map[i][j] && \
	cub3d->map[i][j] != ' ' && cub3d->map[i][j] != '\t')
	{
		if (cub3d->map[i][j] == '0' && !cub3d->map[i][j + 1])
			free_and_exit("[2]not surrounded by walls\n", cub3d);
		if (cub3d->map[i][j] == '0' && (cub3d->map[i + 1][j] == ' '
			|| cub3d->map[i][j + 1] == ' ' || cub3d->map[i - 1][j] == ' '
				|| cub3d->map[i][j - 1] == ' ' || cub3d->map[i + 1][j] == '\t'
			|| cub3d->map[i][j + 1] == '\t' || cub3d->map[i - 1][j] == '\t'
				|| cub3d->map[i][j - 1] == '\t'))
			free_and_exit("[3]not surrounded by walls\n", cub3d);
		if (cub3d->map[i][j] == '0' && (cub3d->map[i + 1][j] == '\0'
			|| cub3d->map[i][j + 1] == '\0' || cub3d->map[i - 1][j] == '\0'
				|| cub3d->map[i][j - 1] == '\0'))
			free_and_exit("[4]not surrounded by walls\n", cub3d);
		j++;
	}
}

void	check_first_and_last(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map[0][i])
	{
		while (cub3d->map[0][i] == ' ' || cub3d->map[0][i] == '\t')
			i++;
		if (cub3d->map[0][i] != '1')
			free_and_exit("[5]not surrounded by walls\n", cub3d);
		i++;
	}
	i = 0;
	while (cub3d->map[cub3d->row_size - 1][i])
	{
		while (cub3d->map[cub3d->row_size - 1][i] == ' ' || \
		cub3d->map[cub3d->row_size - 1][i] == '\t')
			i++;
		if (cub3d->map[cub3d->row_size - 1][i] != '1')
			free_and_exit("[6]not surrounded by walls\n", cub3d);
		i++;
	}
}
