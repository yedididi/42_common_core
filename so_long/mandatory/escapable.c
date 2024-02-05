/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escapable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:21:50 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/28 11:33:07 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long.h"

int	escapable(t_game *mix)
{
	mix->map_c = duplicate(mix->sinnoh.map, mix->sinnoh.y_map);
	mix->c_count_ = count_c(mix, mix->param.x_player, mix->param.y_player, 0);
	mix->map_v = duplicate(mix->sinnoh.map, mix->sinnoh.y_map);
	if ((search_exit(mix, mix->param.x_player, mix->param.y_player, 0) == 1)
		&& (mix->c_count_ == mix->sinnoh.c_count))
		return (1);
	else
		return (0);
}

int	check_wasd(t_game *mix, int x, int y, char c)
{
	char	w_char;
	char	a_char;
	char	s_char;
	char	d_char;

	w_char = mix->map_v[y - 1][x];
	a_char = mix->map_v[y][x - 1];
	s_char = mix->map_v[y + 1][x];
	d_char = mix->map_v[y][x + 1];
	if (c == 'E' && ((w_char == 'E') || (a_char == 'E')
			|| (s_char == 'E') || (d_char == 'E')))
		return ('E');
	else if (c == 'W' && (w_char == '0' || w_char == 'C' || w_char == 'P'))
		return ('W');
	else if (c == 'A' && (a_char == '0' || a_char == 'C' || a_char == 'P'))
		return ('A');
	else if (c == 'S' && (s_char == '0' || s_char == 'C' || s_char == 'P'))
		return ('S');
	else if (c == 'D' && (d_char == '0' || d_char == 'C' || d_char == 'P'))
		return ('D');
	else
		return ('0');
}

int	search_exit(t_game *mix, int x, int y, int num)
{
	if ((x < 0) || (x > mix->sinnoh.x_map) || (y < 0) || (y > mix->sinnoh.y_map)
		|| (mix->map_v[y][x] == 'V') || mix->map_v[y][x] == '1')
		return (num);
	mix->map_v[y][x] = 'V';
	if (check_wasd(mix, x, y, 'E') == 'E')
		return (1);
	if (check_wasd(mix, x, y, 'W') == 'W')
		num = search_exit(mix, x, y - 1, num);
	if (check_wasd(mix, x, y, 'A') == 'A')
		num = search_exit(mix, x - 1, y, num);
	if (check_wasd(mix, x, y, 'S') == 'S')
		num = search_exit(mix, x, y + 1, num);
	if (check_wasd(mix, x, y, 'D') == 'D')
		num = search_exit(mix, x + 1, y, num);
	return (num);
}
