/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:31:08 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/24 11:46:15 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long.h"

void	init(t_game *mix)
{
	init_mix(mix);
	init_param(&(mix->param));
	init_sinnoh(&(mix->sinnoh));
}

void	init_sinnoh(t_map *sinnoh)
{
	sinnoh->map = NULL;
	sinnoh->e_count = 0;
	sinnoh->c_count = 0;
	sinnoh->p_count = 0;
	sinnoh->x_map = 0;
	sinnoh->y_map = 0;
}

void	init_mix(t_game *mix)
{
	mix->mlx_ptr = NULL;
	mix->win_ptr = NULL;
	mix->num = 1;
}

void	init_param(t_param *param)
{
	param->x_player = 0;
	param->y_player = 0;
}
