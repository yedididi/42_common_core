/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:12:46 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/17 15:36:31 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long.h"

void	put_image(t_game mix, char *filename, int x, int y)
{
	int		img_w;
	int		img_h;
	void	*img1;

	img1 = mlx_xpm_file_to_image(mix.mlx_ptr, filename, &img_w, &img_h);
	mlx_put_image_to_window(mix.mlx_ptr, mix.win_ptr, img1, x, y);
}

void	print_map(t_game mix)
{
	int	i;
	int	j;

	i = 0;
	while (mix.sinnoh.map[i])
	{
		j = 0;
		while (mix.sinnoh.map[i][j])
		{
			put_image(mix, "./images/tiles/tile.xpm", j * 32, i * 32);
			decide_tile(mix, mix.sinnoh.map[i][j], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	decide_tile(t_game mix, char c, int x, int y)
{
	if (c == '1')
		put_image(mix, "./images/tiles/wall.xpm", x, y);
	else if (c == 'E')
		put_image(mix, "./images/tiles/exit.xpm", x, y);
	else if (c == 'C')
		put_image(mix, "./images/tiles/collectible.xpm", x, y);
	else if (c == 'P')
		put_image(mix, "./images/Dawn/Dawn_front_00.xpm", x, y);
}
