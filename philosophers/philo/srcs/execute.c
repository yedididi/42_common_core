/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:52:13 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/05 11:33:38 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	execute(t_data *data)
{
	int	i;

	i = 0;
	while (data->nbr_phils > i)
	{
		if (pthread_create(&(data->phil[i].phil_id), NULL,
				start_thread, &(data->phil[i])) != 0)
			return (-1);
		i++;
	}
	end_philo(data);
	return (0);
}

void	*start_thread(void *argv)
{
	int		i;
	t_phil	*phil;

	i = 0;
	phil = (t_phil *)argv;
	if (phil->phil_nbr % 2 == 0)
		usleep(10000);
	while (1)
	{
		if (live(phil) == DEAD)
		{
			print_msg(phil, DEAD);
			pthread_mutex_lock(phil->death_mutex);
			*(phil->death_flag) = DEAD;
			pthread_mutex_unlock(phil->death_mutex);
			return ((void *)DEAD);
		}
		if (check_finish(phil) == FINISHED)
			break ;
	}
	return ((void *)FINISHED);
}

void	end_philo(t_data *data)
{
	int	i;

	i = 0;
	while (data->nbr_phils > i)
	{
		pthread_join(data->phil[i].phil_id, NULL);
		pthread_mutex_destroy(&(data->fork[i].mutex));
		i++;
	}
	pthread_mutex_destroy(&(data->death_mutex));
	pthread_mutex_destroy(&(data->print_mutex));
	free(data->phil);
	free(data->fork);
}

void	print_msg(t_phil *phil, int state)
{
	uint64_t	time;

	time = ft_get_time() - phil->start_time;
	pthread_mutex_lock(phil->print_mutex);
	if (state == TAKE_FORK)
		printf("%llu %d has taken a fork\n", time, phil->phil_nbr);
	if (state == EATING)
		printf("%llu %d is eating\n", time, phil->phil_nbr);
	if (state == SLEEPING)
		printf("%llu %d is sleeping\n", time, phil->phil_nbr);
	if (state == THINKING)
		printf("%llu %d is thinking\n", time, phil->phil_nbr);
	if (state == DEAD)
		printf("%llu %d died\n", time, phil->phil_nbr);
	pthread_mutex_unlock(phil->print_mutex);
}
