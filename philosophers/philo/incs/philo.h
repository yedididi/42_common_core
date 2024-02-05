/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:18:28 by yejlee2           #+#    #+#             */
/*   Updated: 2023/07/19 16:47:17 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

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

typedef struct s_fork
{
	int				state;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_phil
{
	pthread_t		phil_id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	uint64_t		last_eat;
	uint64_t		start_time;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*print_mutex;
	int				phil_nbr;
	int				eat_count;
	int				nbr_of_phils;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_each_eat;
	int				*death_flag;
}	t_phil;

typedef struct s_data
{
	int				nbr_phils;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_each_eat;
	int				death_flag;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
	uint64_t		start_time;
	t_phil			*phil;
	t_fork			*fork;
}	t_data;

int			error(char *str, t_data *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			fill_data(char *argv[], t_data *data);
int			fill_fork(t_data *data);
int			fill_phil(t_data *data);

int			execute(t_data *data);
void		*start_thread(void *argv);
void		end_philo(t_data *data);
void		print_msg(t_phil *phil, int state);

const char	*before_atoi(const char *str);
long long	ft_atoi(const char *str);
int			ft_isnum(int num);
int			ft_strlen(const char *str);
uint64_t	ft_get_time(void);

int			live(t_phil *phil);
int			eat(t_phil *phil);
int			wait_for_forks(t_phil *phil);
int			sleeep(t_phil *phil);
int			think(t_phil *phil);

int			check_death(t_phil *phil);
int			check_finish(t_phil *phil);
int			check_fork(t_phil *phil, t_fork *fork);
void		put_down_fork(t_phil *phil);

#endif