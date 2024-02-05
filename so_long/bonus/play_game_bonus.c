/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:25:42 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/28 11:48:57 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long_bonus.h"

int	key_press(int key, t_game *mix)
{
	int		x_past;
	int		y_past;
	char	*tmp;

	x_past = mix->param.x_player;
	y_past = mix->param.y_player;
	if (key == KEY_W)
		mix->param.y_player--;
	else if (key == KEY_S)
		mix->param.y_player++;
	else if (key == KEY_A)
		mix->param.x_player--;
	else if (key == KEY_D)
		mix->param.x_player++;
	else if (key == KEY_ESC)
		exit(0);
	reset_map(&(mix->sinnoh), &(mix->param), x_past, y_past);
	print_map(*mix);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		mix->num++;
	tmp = ft_itoa(mix->num);
	mlx_string_put(mix->mlx_ptr, mix->win_ptr, 32, 32, 0xFF0000, tmp);
	free (tmp);
	return (0);
}

void	play_game(t_game *mix)
{
	mix->mlx_ptr = mlx_init();
	mix->win_ptr = mlx_new_window(mix->mlx_ptr, 32 * mix->sinnoh.x_map,
			32 * mix->sinnoh.y_map, "pokemon");
	print_map(*mix);
	mlx_key_hook(mix->win_ptr, &key_press, mix);
	mlx_hook(mix->win_ptr, 17, 0, &so_close, 0);
	mlx_loop(mix->mlx_ptr);
}
