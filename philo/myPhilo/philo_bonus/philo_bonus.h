/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:15:36 by yback             #+#    #+#             */
/*   Updated: 2023/03/18 19:31:49 by yback            ###   ########seoul.kr  */
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
	sem_t			can_print;
	sem_t			*forks;
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
	int				forked;
	pthread_t		t_id;
	sem_t			*eating;
	t_data			*data;
	unsigned int	id;
	unsigned int	fork;
	unsigned int	next_fork;
	unsigned int	eating_state;
	long long		last_time_eat;
	long long		last_time_sleep;
}	t_philo;

int		yb_atoi(const char *str);
void	yb_error_handler(void);





#endif