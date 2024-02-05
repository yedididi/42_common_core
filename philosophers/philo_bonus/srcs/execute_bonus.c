/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:52:13 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/05 11:55:21 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

int	execute(t_data *data)
{
	make_process(data);
	if (pthread_create(&(data->monitor_finish), NULL,
			monitor_finish, (void *)data) != 0)
		return (-1);
	if (pthread_detach(data->monitor_finish) != 0)
		return (-1);
	sem_wait(data->death_chk_sem);
	end_philo(data);
	return (0);
}

void	make_process(t_data *data)
{
	pid_t	pid;
	int		i;

	i = 0;
	pid = 1;
	while (data->nbr_phils > i)
	{
		pid = fork();
		if (pid == -1)
			error("Fork error", data);
		else if (pid == 0)
		{
			start_process(&(data->phil[i]));
			exit(0);
		}
		else
			data->phil[i].phil_id = pid;
		i++;
	}
}

void	*start_process(t_phil *phil)
{
	int	i;

	i = 0;
	if (phil->phil_nbr % 2 == 0)
		usleep(1000);
	if (pthread_create(&(phil->monitor_thread), NULL,
			monitor_death, (void *)phil) != 0)
		return ((void *) NULL);
	if (pthread_detach(phil->monitor_thread) != 0)
		return ((void *) 1);
	while (1)
	{
		eat(phil);
		if (check_finish(phil) == FINISHED)
		{
			sem_post(phil->check_finish_sem);
			exit(0);
		}
		sleeep(phil);
		think(phil);
	}
	return ((void *)0);
}

void	end_philo(t_data *data)
{
	int	i;

	i = 0;
	while (data->nbr_phils > i)
	{
		kill(data->phil[i].phil_id, SIGKILL);
		i++;
	}
	sem_close(data->death_sem);
	sem_close(data->print_sem);
	sem_close(data->fork_sem);
	sem_unlink("death_sem");
	sem_unlink("print_sem");
	sem_unlink("fork_sem");
	free(data->phil);
	exit(0);
}

void	print_msg(t_phil *phil, int state)
{
	uint64_t	time;

	time = ft_get_time() - phil->start_time;
	sem_wait(phil->print_sem);
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
	sem_post(phil->print_sem);
}
