/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:07:37 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/18 13:30:15 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long.h"

void	reset_map(t_map *sinnoh, t_param *param, int x_past, int y_past)
{
	if (sinnoh->map[param->y_player][param->x_player] == 'C')
	{
		sinnoh->c_count--;
		locate_player(sinnoh, param, x_past, y_past);
	}
	else if (sinnoh->map[param->y_player][param->x_player] == '1')
		prevent_crush(param, x_past, y_past);
	else if (sinnoh->map[param->y_player][param->x_player] == 'E')
		finish_game(sinnoh, param, x_past, y_past);
	else
		locate_player(sinnoh, param, x_past, y_past);
}

void	prevent_crush(t_param *param, int x_past, int y_past)
{
	param->x_player = x_past;
	param->y_player = y_past;
}

void	locate_player(t_map *sinnoh, t_param *param, int x_past, int y_past)
{
	sinnoh->map[y_past][x_past] = '0';
	sinnoh->map[param->y_player][param->x_player] = 'P';
}

void	finish_game(t_map *sinnoh, t_param *param, int x_past, int y_past)
{
	if (sinnoh->c_count == 0)
		exit(0);
	else
	{
		write(1, "you have to collect everything in the map before exit\n", 54);
		param->x_player = x_past;
		param->y_player = y_past;
	}
}
