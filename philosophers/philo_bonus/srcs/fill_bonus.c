/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:25:33 by yejlee2           #+#    #+#             */
/*   Updated: 2023/07/26 12:27:56 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

int	fill_data(char *argv[], t_data *data)
{
	data->nbr_phils = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start_time = ft_get_time();
	data->death_flag = ALIVE;
	if (argv[5] != NULL)
		data->nbr_each_eat = ft_atoi(argv[5]);
	else
		data->nbr_each_eat = -1;
	if ((data->nbr_phils < 1) || (data->time_to_die <= 0)
		|| (data->time_to_eat <= 0) || (data->time_to_sleep <= 0)
		|| ((data->nbr_each_eat < 0) && (argv[5] != NULL)))
		return (-1);
	if (fill_bonus(data) == -1)
		return (-1);
	return (0);
}

int	fill_bonus(t_data *data)
{
	sem_unlink("death_sem");
	sem_unlink("print_sem");
	sem_unlink("fork_sem");
	sem_unlink("eat_sem");
	sem_unlink("death_chk_sem");
	data->fork_sem = sem_open("fork_sem", O_CREAT, S_IRWXU, data->nbr_phils);
	data->death_sem = sem_open("death_sem", O_CREAT, S_IRWXU, 1);
	data->print_sem = sem_open("print_sem", O_CREAT, S_IRWXU, 1);
	data->death_chk_sem = sem_open("death_chk_sem", O_CREAT, 0777, 0);
	if (data->death_sem == SEM_FAILED || data->print_sem == SEM_FAILED
		|| data->fork_sem == SEM_FAILED || data->death_chk_sem == SEM_FAILED)
		return (-1);
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
		if (fill_phil_bonus(data, i) == -1)
			return (-1);
		data->phil[i].last_eat = ft_get_time();
		data->phil[i].start_time = data->start_time;
		data->phil[i].eat_count = 0;
		data->phil[i].phil_nbr = i + 1;
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

int	fill_phil_bonus(t_data *data, int i)
{
	sem_unlink("death_chk_sem");
	sem_unlink("last_eat_sem");
	data->phil[i].fork_sem = data->fork_sem;
	data->phil[i].death_sem = data->death_sem;
	data->phil[i].print_sem = data->print_sem;
	data->phil[i].death_chk_sem = data->death_chk_sem;
	data->phil[i].check_finish_sem = sem_open("check_finish_sem",
			O_CREAT, S_IRWXU, 0);
	data->phil[i].last_eat_sem = sem_open("last_eat_sem",
			O_CREAT, S_IRWXU, 1);
	if (data->phil[i].check_finish_sem == SEM_FAILED
		|| data->phil[i].last_eat_sem == SEM_FAILED)
		return (-1);
	return (0);
}
