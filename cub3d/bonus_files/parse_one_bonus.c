/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_one_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:09:16 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 12:53:42 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	parse_file(t_cub3d *cub3d)
{
	char	*line;
	int		fd;

	fd = open(cub3d->file_name, O_RDONLY);
	if (fd == -1)
		free_and_exit("invalid file\n", cub3d);
	line = parse_info(cub3d, fd);
	parse_map(cub3d, fd, line);
	close(fd);
	return (0);
}

int	is_it_map(char *line)
{
	if (line && (line[0] == '\n' || line[0] == '\0'))
		return (0);
	if (!line || ft_strlen(line) < 2)
		return (1);
	if (found_map(line))
		return (2);
	if (line[0] == 'N' && line[1] == 'O')
		return (0);
	else if (line[0] == 'S' && line[1] == 'O')
		return (0);
	else if (line[0] == 'W' && line[1] == 'E')
		return (0);
	else if (line[0] == 'E' && line[1] == 'A')
		return (0);
	else if (line[0] == 'F' && line[1] == ' ')
		return (0);
	else if (line[0] == 'C' && line[1] == ' ')
		return (0);
	else
		return (1);
	return (0);
}

void	get_map_row_col(char *line, t_cub3d *cub3d)
{
	int	col_size;

	col_size = 0;
	if (ft_all_white(line) == 1)
		return (blank_flag(cub3d));
	while (line[col_size] != '\0')
	{
		check_another_map(cub3d);
		if (line[col_size] == 'N' || line[col_size] == 'S'
			|| line[col_size] == 'E' || line[col_size] == 'W')
		{
			if (cub3d->player == 0)
				set_player_info(cub3d, line[col_size], col_size);
			else
				free_and_exit("more than 1 player\n", cub3d);
		}
		col_size++;
	}
	if (cub3d->col_size < col_size)
		cub3d->col_size = col_size;
	cub3d->row_size++;
}

char	*pass_info(char *line, int fd)
{
	int		value;

	value = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		value = is_it_map(line);
		if (value == 2)
			break ;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (line);
}

void	get_size(t_cub3d *cub3d)
{
	int		fd;
	int		value;
	char	*line;

	value = 0;
	line = NULL;
	fd = open(cub3d->file_name, O_RDONLY);
	if (fd == -1)
		free_and_exit("invalid file\n", cub3d);
	line = pass_info(line, fd);
	while (line != NULL)
	{
		get_map_row_col(line, cub3d);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
}
