/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:24:14 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/05 11:03:35 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (error("argc error", &data));
	if (fill_data(argv, &data) == -1)
		return (error("fill_data error", &data));
	if (fill_fork(&data) == -1)
		return (error("fill_fork error", &data));
	if (fill_phil(&data) == -1)
		return (error("fill_phil error", &data));
	if (execute(&data) == -1)
		return (error("execute error", &data));
	return (0);
}

int	error(char *str, t_data *data)
{
	if (ft_strncmp(str, "fill_fork error", ft_strlen(str)) == 0)
		free(data->fork);
	if (ft_strncmp(str, "fill_phil error", ft_strlen(str)) == 0)
	{
		free(data->fork);
		free(data->phil);
	}
	printf("%s\n", str);
	return (-1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
