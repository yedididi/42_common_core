/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:26:05 by yejlee2           #+#    #+#             */
/*   Updated: 2023/07/19 14:53:39 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	check_death(t_phil *phil)
{
	int	starve;

	pthread_mutex_lock(phil->death_mutex);
	starve = ft_get_time() - (uint64_t)phil->last_eat;
	if (phil->time_to_die <= starve || *(phil->death_flag) == DEAD)
	{
		pthread_mutex_unlock(phil->death_mutex);
		return (DEAD);
	}
	else
	{
		pthread_mutex_unlock(phil->death_mutex);
		return (ALIVE);
	}
}

int	check_finish(t_phil *phil)
{
	if (phil->eat_count == phil->nbr_each_eat)
		return (FINISHED);
	else
		return (NOT_FINISHED);
}

int	check_fork(t_phil *phil, t_fork *fork)
{
	while (1)
	{
		if (check_death(phil) == DEAD)
			return (DEAD);
		pthread_mutex_lock(&(fork->mutex));
		if (fork->state == NOT_TAKEN)
		{
			fork->state = TAKEN;
			print_msg(phil, TAKE_FORK);
			pthread_mutex_unlock(&(fork->mutex));
			return (TAKE_FORK);
		}
		pthread_mutex_unlock(&(fork->mutex));
		usleep(100);
	}
}

void	put_down_fork(t_phil *phil)
{
	pthread_mutex_lock(&(phil->left_fork->mutex));
	phil->left_fork->state = NOT_TAKEN;
	pthread_mutex_unlock(&(phil->left_fork->mutex));
	pthread_mutex_lock(&(phil->right_fork->mutex));
	phil->right_fork->state = NOT_TAKEN;
	pthread_mutex_unlock(&(phil->right_fork->mutex));
}
