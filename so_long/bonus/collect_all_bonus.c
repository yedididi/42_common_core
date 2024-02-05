/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:28:36 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/28 11:32:41 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long_bonus.h"

int	count_c(t_game *mix, int x, int y, int num)
{
	if ((x < 0) || (x > mix->sinnoh.x_map) || (y < 0) || (y > mix->sinnoh.y_map)
		|| (mix->map_c[y][x] == 'V') || (mix->map_c[y][x] == '1'))
		return (num);
	if (mix->map_c[y][x] == 'C')
		num++;
	mix->map_c[y][x] = 'V';
	if (check_wasd_c(mix, x, y, 'W') == 'W')
		num = count_c(mix, x, y - 1, num);
	if (check_wasd_c(mix, x, y, 'A') == 'A')
		num = count_c(mix, x - 1, y, num);
	if (check_wasd_c(mix, x, y, 'S') == 'S')
		num = count_c(mix, x, y + 1, num);
	if (check_wasd_c(mix, x, y, 'D') == 'D')
		num = count_c(mix, x + 1, y, num);
	return (num);
}

int	check_wasd_c(t_game *mix, int x, int y, char c)
{
	char	w_char;
	char	a_char;
	char	s_char;
	char	d_char;

	w_char = mix->map_c[y - 1][x];
	a_char = mix->map_c[y][x - 1];
	s_char = mix->map_c[y + 1][x];
	d_char = mix->map_c[y][x + 1];
	if ((c == 'E') && ((w_char == 'E') || (a_char == 'E')
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
