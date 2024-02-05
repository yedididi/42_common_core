/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:53 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/18 13:17:31 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long_bonus.h"

void	check_map(char *map_name, t_map *sinnoh, t_param *param)
{
	int	tmp;

	tmp = 0;
	open_map(map_name, sinnoh);
	first_check(sinnoh->map[0], sinnoh);
	while (sinnoh->map[tmp])
	{
		middle_check(sinnoh->map[tmp], sinnoh, param);
		tmp++;
	}
	last_check(sinnoh->map[tmp - 1]);
	if (sinnoh->c_count == 0 || sinnoh->e_count != 1 || sinnoh->p_count != 1)
		error("invalid map8");
}

void	first_check(char *str, t_map *sinnoh)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], "1", 1) != 0)
			error("invalid map3");
		i++;
	}
	sinnoh->x_map = i;
	sinnoh->y_map = 0;
}

void	middle_check(char *str, t_map *sinnoh, t_param *param)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], "C", 1) == 0)
			(sinnoh->c_count)++;
		else if (ft_strncmp(&str[i], "E", 1) == 0)
			(sinnoh->e_count)++;
		else if (ft_strncmp(&str[i], "P", 1) == 0)
		{
			param->x_player = i;
			param->y_player = sinnoh->y_map;
			(sinnoh->p_count)++;
		}
		else if (ft_strncmp(&str[i], "0", 1) != 0
			&& ft_strncmp(&str[i], "1", 1) != 0)
			error("invalid map5");
		i++;
	}
	if ((sinnoh->x_map != i) || (str[0] != '1') || (str[i - 1] != '1'))
		error("invalid map6");
	sinnoh->y_map = sinnoh->y_map + 1;
}

void	last_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], "1", 1) != 0)
			error("invalid map7");
		i++;
	}
}
