/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:51:36 by yback             #+#    #+#             */
/*   Updated: 2023/03/17 09:47:09 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_data
{
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	struct s_philo	**philos;
	unsigned int	nb;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	not_dead;
	unsigned int	i;
	unsigned int	eat_time;
	int				nb_me;
	long long		time_var;
	int  			end;
}	t_data;

typedef struct s_philo
{
	pthread_t		overseer;
	pthread_t		controller;
	pthread_t		t_id;
	pthread_mutex_t	eating;
	t_data			*data;
	unsigned int	id;
	unsigned int	fork;
	unsigned int	next_fork;
	unsigned int	eating_state;
	long long		last_meal;
	long long		last_sleep;
}	t_philo;

void			ft_error_handler(void);
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			ft_set_data(int argc, char *argv[], t_data *data);
void			free_philo(t_data *data);
void			create_philo(t_data *data);
t_philo			**init_philos(t_data *data);
pthread_mutex_t	*init_forks(t_data *data);
void			*monitor(void *data);
void			*philo_routine(void *data);
void			philo_sleeping(t_philo *ph);
void			philo_eating(t_philo *ph);
void			philo_thinking(t_philo *ph);
void			ft_print(t_data *data, int pid, char *str, int isdead);
long long		ft_get_time(void);

#endif