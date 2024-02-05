/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contents_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:29:17 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 13:01:18 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d_bonus.h"

static int	set_color(char *line, t_cub3d *cub3d, int *fc_color, int flag)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	while (line[i] && j < 3)
	{
		color = ft_atoi(line + i);
		if (color < 0 || color > 255)
			return (1);
		fc_color[j] = color;
		while (line[i] && line[i] != ',')
			i++;
		if (line[i] == ',')
			i++;
		j++;
	}
	if (j != 3 || line[i])
		return (1);
	if (flag == 'f')
		cub3d->floor = (fc_color[0] << 16) | (fc_color[1] << 8) | fc_color[2];
	else if (flag == 'c')
		cub3d->ceiling = (fc_color[0] << 16) | (fc_color[1] << 8) | fc_color[2];
	return (0);
}

static int	set_colors(char *line, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	if (line[0] == 'F' && line[1] == ' ' && cub3d->f_color[0] == -1)
	{
		i = ft_isspace(line + 1);
		if (set_color(line + 1 + i, cub3d, cub3d->f_color, 'f'))
			return (1);
	}
	else if (line[0] == 'C' && line[1] == ' ' && cub3d->c_color[0] == -1)
	{
		i = ft_isspace(line + 1);
		if (set_color(line + 1 + i, cub3d, cub3d->c_color, 'c'))
			return (1);
	}
	if (cub3d->floor && cub3d->ceiling && check_same_color(cub3d))
		free_and_exit("Duplicate RGB colors\n", cub3d);
	return (0);
}

static void	set_path(char *line, t_cub3d *cub3d, char **result)
{
	int		i;
	int		fd;
	char	**split;
	char	*tmp;

	split = NULL;
	tmp = ft_strndup(line, ft_strlen(line) - 1);
	split = ft_split(tmp, ' ');
	free(tmp);
	if (!split)
		free_and_exit("ft_split: Failed.", cub3d);
	i = 0;
	while (split[i])
		i++;
	if (i != 2)
	{
		free_split(split);
		free_and_exit("Too many texture files.", cub3d);
	}
	*result = ft_strdup(split[1]);
	fd = open(*result, O_RDONLY);
	if (fd == -1)
		free_and_exit("open: Cannot open a texture path.", cub3d);
	close(fd);
	free_split(split);
}

static void	check_path(char *line, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	if (ft_strlen(line) < 4)
		free_and_exit("ft_strlen: Invalid a texture path.", cub3d);
	if (line[0] == 'N' && line[1] == 'O' && !cub3d->no_path)
		set_path(line, cub3d, &(cub3d->no_path));
	else if (line[0] == 'S' && line[1] == 'O' && !cub3d->so_path)
		set_path(line, cub3d, &(cub3d->so_path));
	else if (line[0] == 'W' && line[1] == 'E' && !cub3d->we_path)
		set_path(line, cub3d, &(cub3d->we_path));
	else if (line[0] == 'E' && line[1] == 'A' && !cub3d->ea_path)
		set_path(line, cub3d, &(cub3d->ea_path));
}

int	check_contents(char *line, t_cub3d *cub3d)
{
	if (cub3d->no_path && cub3d->so_path && cub3d->we_path && cub3d->ea_path && \
	cub3d->f_color[0] != -1 && cub3d->c_color[0] != -1)
	{
		cub3d->contents = 1;
		if (found_map(line))
			return (-1);
	}
	else if (found_map(line))
		return (1);
	if (line && (line[0] == '\0' || line[0] == '\t' \
		|| ft_isspace(line) == ft_strlen(line)))
		return (0);
	check_path(line, cub3d);
	if (set_colors(line, cub3d))
		return (1);
	else
		return (0);
	return (1);
}
