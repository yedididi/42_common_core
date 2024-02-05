/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:24:14 by yejlee2           #+#    #+#             */
/*   Updated: 2023/07/26 10:57:39 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 5 && argc != 6)
		error("argc error", &data);
	if (fill_data(argv, &data) == -1)
		error("fill_data error", &data);
	if (fill_phil(&data) == -1)
		error("fill_phil error", &data);
	if (execute(&data) == -1)
		error("execute error", &data);
	return (0);
}

int	error(char *str, t_data *data)
{
	if (ft_strncmp(str, "fill_phil error", ft_strlen(str)) == 0)
		free(data->phil);
	printf("%s\n", str);
	exit(1);
}

uint64_t	ft_get_time(void)
{
	uint64_t		return_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (return_time);
}
