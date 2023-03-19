/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:52:16 by yback             #+#    #+#             */
/*   Updated: 2023/03/16 21:52:17 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>

typedef struct s_data
{
	sem_t			*print;
	sem_t			*forks;
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
}	t_data;

typedef struct s_philo
{
	pthread_t		overseer;
	int				forked;
	pthread_t		t_id;
	sem_t			*eating;
	t_data			*data;
	unsigned int	id;
	unsigned int	fork;
	unsigned int	next_fork;
	unsigned int	eating_state;
	long long		last_meal;
	long long		last_sleep;
}	t_philo;

void		ft_error_handler(void);
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_set_data(int argc, char *argv[], t_data *data);
void		create_philo(t_data *data);
sem_t		*init_forks(t_data *data);
t_philo		**init_philos(t_data *data);
void		*monitor(void *data);
void		*philo_routine(void *data);
void		ft_actions(t_philo *ph);
void		philo_sleeping(t_philo *ph);
void		philo_eating(t_philo *ph);
void		philo_thinking(t_philo *ph);
void		ft_print(t_data *data, int pid, char *str, int isdead);
void		end_philo(t_data *data);
long long	ft_get_time(void);

#endif