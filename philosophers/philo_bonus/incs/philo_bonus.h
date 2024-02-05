/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:18:28 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/05 11:54:58 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <sys/time.h>
# include <signal.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>

typedef enum e_fork_state
{
	TAKEN,
	NOT_TAKEN,
}	t_fork_state;

typedef enum e_phil_state
{
	TAKE_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	ALIVE,
}	t_phil_state;

typedef enum e_program_state
{
	FINISHED,
	NOT_FINISHED,
}	t_program_state;

typedef struct s_phil
{
	pid_t		phil_id;
	pid_t		death_pid;
	uint64_t	last_eat;
	uint64_t	start_time;
	sem_t		*fork_sem;
	sem_t		*death_sem;
	sem_t		*print_sem;
	sem_t		*last_eat_sem;
	sem_t		*death_chk_sem;
	sem_t		*check_finish_sem;
	pthread_t	monitor_thread;
	int			eat_count;
	int			phil_nbr;
	int			nbr_of_phils;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_each_eat;
	int			*death_flag;
}	t_phil;

typedef struct s_data
{
	int			nbr_phils;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_each_eat;
	int			death_flag;
	pid_t		death_pid;
	sem_t		*fork_sem;
	sem_t		*death_sem;
	sem_t		*print_sem;
	sem_t		*death_chk_sem;
	pthread_t	monitor_finish;
	uint64_t	start_time;
	t_phil		*phil;
}	t_data;

int			error(char *str, t_data *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			fill_data(char *argv[], t_data *data);
int			fill_phil(t_data *data);
int			fill_bonus(t_data *data);
int			fill_phil_bonus(t_data *data, int i);

int			execute(t_data *data);
void		make_process(t_data *data);
void		*start_process(t_phil *phil);
void		end_philo(t_data *data);
void		print_msg(t_phil *phil, int state);

const char	*before_atoi(const char *str);
long long	ft_atoi(const char *str);
int			ft_isnum(int num);
int			ft_strlen(const char *str);
uint64_t	ft_get_time(void);

void		eat(t_phil *phil);
void		wait_for_forks(t_phil *phil);
void		put_down_fork(t_phil *phil);
void		sleeep(t_phil *phil);
void		think(t_phil *phil);

void		*monitor_death(void *argv);
void		*monitor_finish(void *argv);
int			check_finish(t_phil *phil);

#endif