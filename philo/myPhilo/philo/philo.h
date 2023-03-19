/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:45:47 by yback             #+#    #+#             */
/*   Updated: 2023/03/18 15:35:16 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data
{
	pthread_mutex_t	can_print;
	pthread_mutex_t	*forks;
	struct s_philo	**philos;
	unsigned int	philo_num;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	not_dead;
	unsigned int	one_philo;
	unsigned int	eat_count;
	int				must_eat_num;
	long long		time_var;
	int  			end;
}	t_data;

typedef struct s_philo
{
	pthread_t		overseer;
	pthread_t		thread_storage;
	pthread_t		t_id;
	pthread_mutex_t	eating;
	t_data			*data;
	unsigned int	id;
	unsigned int	fork;
	unsigned int	next_fork;
	unsigned int	eating_state;
	long long		last_time_eat;
	long long		last_time_sleep;
}	t_philo;

void			yb_error_handler(void);
int				yb_atoi(const char *str);
pthread_mutex_t	*init_forks(t_data *data);
t_philo			**init_philos(t_data *data);
long long		yb_get_time(void);
void			philo_thinking(t_philo *philo);
void			philo_eating(t_philo *philo);
void			philo_sleeping(t_philo *philo);
void			*philo_routine(void *data);
void			yb_print(t_data *data, int pid, char *str, int is_dead);
void			*monitor(void *data);

#endif