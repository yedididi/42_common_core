/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:26:05 by yejlee2           #+#    #+#             */
/*   Updated: 2023/07/26 10:55:37 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

// int	check_death(t_phil *phil)
// {
// 	int	starve;

// 	sem_wait(phil->death_sem);
// 	starve = ft_get_time() - (uint64_t)phil->last_eat;
// 	if (phil->time_to_die <= starve)
// 	{
// 		sem_post(phil->death_sem);
// 		return (DEAD);
// 	}
// 	else
// 	{
// 		sem_post(phil->death_sem);
// 		return (ALIVE);
// 	}
// }

int	check_finish(t_phil *phil)
{
	if (phil->eat_count == phil->nbr_each_eat)
		return (FINISHED);
	else
		return (NOT_FINISHED);
}
