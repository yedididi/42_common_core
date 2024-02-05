/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:54:49 by yejlee2           #+#    #+#             */
/*   Updated: 2023/07/19 13:23:24 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	live(t_phil *phil)
{
	if (eat(phil) == DEAD)
		return (DEAD);
	if (check_finish(phil) == FINISHED)
		return (FINISHED);
	if (sleeep(phil) == DEAD)
		return (DEAD);
	if (think(phil) == DEAD)
		return (DEAD);
	return (ALIVE);
}

int	eat(t_phil *phil)
{
	uint64_t	now;

	if (check_death(phil) == DEAD)
		return (DEAD);
	if (wait_for_forks(phil) == DEAD)
		return (DEAD);
	now = ft_get_time();
	print_msg(phil, EATING);
	phil->last_eat = ft_get_time();
	while ((int)(ft_get_time() - now) < phil->time_to_eat)
	{
		if (check_death(phil) == DEAD)
			return (DEAD);
		usleep(100);
	}
	put_down_fork(phil);
	phil->eat_count++;
	return (SLEEPING);
}

int	wait_for_forks(t_phil *phil)
{
	if (check_fork(phil, phil->left_fork) == DEAD)
		return (DEAD);
	if (check_fork(phil, phil->right_fork) == DEAD)
		return (DEAD);
	return (TAKE_FORK);
}

int	sleeep(t_phil *phil)
{
	uint64_t	now;

	now = ft_get_time();
	if (check_death(phil) == DEAD)
		return (DEAD);
	print_msg(phil, SLEEPING);
	while ((int)(ft_get_time() - now) < phil->time_to_sleep)
	{
		if (check_death(phil) == DEAD)
			return (DEAD);
		usleep(100);
	}
	return (THINKING);
}

int	think(t_phil *phil)
{
	if (check_death(phil) == DEAD)
		return (DEAD);
	print_msg(phil, THINKING);
	return (THINKING);
}
