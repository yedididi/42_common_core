/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:53:08 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/30 11:35:47 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long_bonus.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_memset(str[i], 0, ft_strlen(str[i]));
		free(str[i]);
		i++;
	}
	ft_memset(str, 0, 1);
	free(str);
}

char	**duplicate(char **map, int size)
{
	char	**return_str;
	int		i;

	i = 0;
	return_str = (char **)malloc(sizeof(char *) * (size + 1));
	if (return_str == 0)
		error("malloc error");
	while (map[i])
	{
		return_str[i] = ft_strdup(map[i]);
		if (return_str[i] == 0)
			error("malloc error");
		i++;
	}
	return_str[i] = 0;
	return (return_str);
}

void	open_map(char *map_name, t_map *sinnoh)
{
	char	*str;
	int		fd;
	int		size;
	int		tmp;

	size = get_size(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error("can't open map");
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		error("malloc error");
	tmp = read(fd, str, size);
	if (tmp < 0)
		error("read error");
	close(fd);
	str[size] = '\0';
	sinnoh->map = ft_split(str, '\n');
	free(str);
}

int	get_size(char *map_name)
{
	int		fd;
	int		size;
	int		tmp;
	char	buf[4096];

	size = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error("can't open file");
	while (1)
	{
		tmp = read(fd, buf, 4096);
		if (tmp == 0)
			break ;
		else if (tmp < 0)
			error("read error");
		else
			size = size + tmp;
	}
	close(fd);
	return (size);
}

int	so_close(void)
{
	exit(0);
}
