/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:25:33 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/05 10:59:37 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	fill_data(char *argv[], t_data *data)
{
	data->nbr_phils = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start_time = ft_get_time();
	data->death_flag = ALIVE;
	if (pthread_mutex_init(&(data->death_mutex), NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&(data->print_mutex), NULL) != 0)
		return (-1);
	if (argv[5] != NULL)
		data->nbr_each_eat = ft_atoi(argv[5]);
	if ((data->nbr_phils < 1) || (data->time_to_die <= 0)
		|| (data->time_to_eat <= 0) || (data->time_to_sleep <= 0)
		|| ((data->nbr_each_eat < 0) && (argv[5] != NULL)))
		return (-1);
	return (0);
}

int	fill_fork(t_data *data)
{
	int	i;

	i = 0;
	data->fork = (t_fork *)malloc(sizeof(t_fork) * data->nbr_phils);
	if (data->fork == 0)
		return (-1);
	while (data->nbr_phils > i)
	{
		data->fork[i].state = NOT_TAKEN;
		if (pthread_mutex_init(&data->fork[i].mutex, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	fill_phil(t_data *data)
{
	int	i;

	i = 0;
	data->phil = (t_phil *)malloc(sizeof(t_phil) * data->nbr_phils);
	if (data->phil == 0)
		return (-1);
	while (data->nbr_phils > i)
	{
		data->phil[i].left_fork = &data->fork[i];
		data->phil[i].right_fork = &data->fork[(i + 1) % data->nbr_phils];
		data->phil[i].last_eat = ft_get_time();
		data->phil[i].start_time = data->start_time;
		data->phil[i].death_mutex = &(data->death_mutex);
		data->phil[i].print_mutex = &(data->print_mutex);
		data->phil[i].phil_nbr = i + 1;
		data->phil[i].eat_count = 0;
		data->phil[i].nbr_of_phils = data->nbr_phils;
		data->phil[i].time_to_die = data->time_to_die;
		data->phil[i].time_to_eat = data->time_to_eat;
		data->phil[i].time_to_sleep = data->time_to_sleep;
		data->phil[i].nbr_each_eat = data->nbr_each_eat;
		data->phil[i].death_flag = &(data->death_flag);
		i++;
	}
	return (0);
}
