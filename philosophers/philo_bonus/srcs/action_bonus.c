/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:54:49 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/05 11:51:03 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

void	eat(t_phil *phil)
{
	uint64_t	now;

	wait_for_forks(phil);
	now = ft_get_time();
	print_msg(phil, EATING);
	phil->last_eat = ft_get_time();
	while ((int)(ft_get_time() - now) < phil->time_to_eat)
		usleep(100);
	put_down_fork(phil);
	phil->eat_count++;
}

void	wait_for_forks(t_phil *phil)
{
	sem_wait(phil->fork_sem);
	print_msg(phil, TAKE_FORK);
	sem_wait(phil->fork_sem);
	print_msg(phil, TAKE_FORK);
}

void	put_down_fork(t_phil *phil)
{
	sem_post(phil->fork_sem);
	sem_post(phil->fork_sem);
}

void	sleeep(t_phil *phil)
{
	uint64_t	now;

	now = ft_get_time();
	print_msg(phil, SLEEPING);
	while ((int)(ft_get_time() - now) < phil->time_to_sleep)
		usleep(100);
}

void	think(t_phil *phil)
{
	print_msg(phil, THINKING);
}
