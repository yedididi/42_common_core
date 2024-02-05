/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:10:11 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/05 11:51:51 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

void	*monitor_death(void *argv)
{
	t_phil		*phil;
	uint64_t	starve;

	phil = (t_phil *)argv;
	usleep(phil->time_to_die * 1000);
	while (1)
	{
		starve = ft_get_time() - phil->last_eat;
		if ((uint64_t)phil->time_to_die <= starve)
		{
			print_msg(phil, DEAD);
			sem_post(phil->death_chk_sem);
			return ((void *)DEAD);
		}
		usleep(1000);
	}
}

void	*monitor_finish(void *argv)
{
	t_data		*data;
	int			i;

	i = 0;
	data = (t_data *)argv;
	usleep(data->time_to_die * 1000);
	if (data->nbr_each_eat < 0)
		return ((void *) 0);
	while (data->nbr_phils > i)
	{
		sem_wait(data->phil[i].check_finish_sem);
		i++;
	}
	sem_post(data->phil->death_chk_sem);
	return ((void *) 0);
}
