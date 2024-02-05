/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:35:27 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 15:52:54 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

static void	invalid_map(t_cub3d *cub3d, char *line, int fd)
{
	int	i;

	i = 0;
	if (!line)
		free_and_exit("Failed strndup\n", cub3d);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N' || \
		line[i] == 'S' || line[i] == 'W' || line[i] == 'E' \
		|| line[i] == ' ' || line[i] == '\t')
			i++;
		else
		{
			close(fd);
			free_and_exit("Wrong map character!\n", cub3d);
		}
	}
}

char	*parse_info(t_cub3d *cub3d, int fd)
{
	int		value;
	char	*line;

	value = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		value = check_contents(line, cub3d);
		if (value == -1)
			break ;
		else if (value == 1)
		{
			close(fd);
			free(line);
			free_and_exit("wrong map\n", cub3d);
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (line);
}

void	parse_map(t_cub3d *cub3d, int fd, char *line)
{
	int	i;

	i = 0;
	cub3d->map = (char **)malloc(sizeof(char *) * (cub3d->row_size + 1));
	if (cub3d->map == 0)
		free_and_exit("Failed map malloc\n", cub3d);
	while (i < cub3d->row_size)
		cub3d->map[i++] = NULL;
	i = 0;
	while (line != NULL)
	{
		if (ft_all_white(line) != 1)
		{
			if (is_enter(line) == 1)
				cub3d->map[i] = ft_strndup(line, ft_strlen(line) - 1);
			else
				cub3d->map[i] = ft_strndup(line, ft_strlen(line));
			invalid_map(cub3d, cub3d->map[i], fd);
			i++;
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	cub3d->map[cub3d->row_size] = NULL;
}
