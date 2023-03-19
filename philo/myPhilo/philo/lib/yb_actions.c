/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yb_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:10:47 by yback             #+#    #+#             */
/*   Updated: 2023/03/19 17:26:26 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	yb_print(t_data *data, int pid, char *str, int is_dead)
{
	pthread_mutex_lock(&data->can_print);
	if (!data->end)
		printf("%lld %d %s\n", yb_get_time() - data->time_var, pid, str);
	if (!is_dead)
		pthread_mutex_unlock(&data->can_print);
}

void	philo_thinking(t_philo *philo)
{
	yb_print(philo->data, philo->id, "is thinking", 0);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->fork]);
	yb_print(philo->data, philo->id, "has taken a fork", 0);
	pthread_mutex_lock(&philo->data->forks[philo->next_fork]);
	yb_print(philo->data, philo->id, "has taken a fork", 0);
	pthread_mutex_lock(&philo->eating);
	yb_print(philo->data, philo->id, "is eating", 0);
	philo->data->eat_count++;
	philo->eating_state = 1;
	philo->last_time_eat = yb_get_time();
	if (philo->data->time_eat > 0)
		usleep(philo->data->time_eat * 1000);
	philo->eating_state = 0;
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(&philo->data->forks[philo->fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->next_fork]);
}

void	philo_sleeping(t_philo *philo)
{
	philo->last_time_sleep = yb_get_time();
	yb_print(philo->data, philo->id, "is sleeping", 0);
	if (philo->data->time_sleep > 0)
		usleep(philo->data->time_sleep * 1000);
	while (philo->last_time_sleep + philo->data->time_sleep > yb_get_time())
		continue;
}