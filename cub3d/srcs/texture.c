/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:53:02 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 11:34:15 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

//choose if it is north, south, east, west
int	get_texnum(t_cub3d *cub3d, t_dda *dda)
{
	int	texnum;

	(void)cub3d;
	if (dda->side == 0)
	{
		if (dda->step_x == -1)
			texnum = 3;
		else
			texnum = 2;
	}
	else
	{
		if (dda->step_y == -1)
			texnum = 0;
		else
			texnum = 1;
	}
	return (texnum);
}

t_img	*set_image(t_cub3d *cub3d, char *path, int num)
{
	t_img	*img;

	img = &cub3d->texture_file[num];
	img = &cub3d->texture_file[num];
	img->img_ptr = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
			path, &img->size_w, &img->size_h);
	if (!img->img_ptr)
		free_and_exit("texture file open fail\n", cub3d);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->size_l, &img->endian);
	if (!img->data)
		free_and_exit("texture file open fail\n", cub3d);
	return (img);
}

int	*open_texture(t_cub3d *cub3d, int num, char *path)
{
	int		*texture;
	t_img	*img;
	int		i;
	int		j;

	img = set_image(cub3d, path, num);
	texture = (int *)malloc(sizeof(int) * (img->size_w * img->size_h));
	if (!texture)
		free_and_exit("malloc fail\n", cub3d);
	i = 0;
	while (i < img->size_h)
	{
		j = 0;
		while (j < img->size_w)
		{
			texture[img->size_w * i + j] = img->data[img->size_w * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(cub3d->mlx->mlx_ptr, img->img_ptr);
	return (texture);
}
