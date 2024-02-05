/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:34:39 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/30 11:38:51 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long_bonus.h"

void	put_enemy(t_game *mix)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (x < mix->sinnoh.x_map)
	{
		while (y < mix->sinnoh.y_map)
		{
			if ((x % 2 == 1) && (y % 5 == 2) && (mix->sinnoh.map[y][x] == '0'))
			{
				mix->sinnoh.map[y][x] = 'G';
				return ;
			}
			y++;
		}
		x++;
	}
}

void	move_enemy(t_map *sinnoh)
{
	int	i;
	int	j;

	i = 0;
	while (sinnoh->map[i])
	{
		j = 0;
		while (sinnoh->map[i][j])
		{
			if (sinnoh->map[i][j] == 'G')
			{
				decide_enemy(sinnoh, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_right(t_map *sinnoh, int i, int j)
{
	sinnoh->map[i][j] = '0';
	sinnoh->map[i][j + 1] = 'G';
}

void	move_left(t_map *sinnoh, int i, int j)
{
	sinnoh->map[i][j] = '0';
	sinnoh->map[i][j - 1] = 'G';
}

void	decide_enemy(t_map *sinnoh, int i, int j)
{
	if (sinnoh->flag == 1)
	{
		if ((sinnoh->map[i][j + 1] == '0') || (sinnoh->map[i][j + 1] == 'P'))
			move_right(sinnoh, i, j);
		else if ((sinnoh->map[i][j - 1] == '0')
			|| (sinnoh->map[i][j - 1] == 'P'))
		{
			move_left(sinnoh, i, j);
			sinnoh->flag = -1;
		}
	}
	else if (sinnoh->flag == -1)
	{
		if ((sinnoh->map[i][j - 1] == '0') || (sinnoh->map[i][j - 1] == 'P'))
			move_left(sinnoh, i, j);
		else if ((sinnoh->map[i][j + 1] == '0')
			|| (sinnoh->map[i][j + 1] == 'P'))
		{
			move_right(sinnoh, i, j);
			sinnoh->flag = 1;
		}
	}
}
