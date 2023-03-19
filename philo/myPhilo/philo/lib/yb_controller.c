/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yb_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:46:46 by yback             #+#    #+#             */
/*   Updated: 2023/03/19 17:46:27 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	yb_get_time(void)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	return (ct.tv_sec * 1000LL + ct.tv_usec / 1000);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->data->not_dead)
	{
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
		usleep(200);
	}
	return (NULL);
}

void	*monitor(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (philo->data->not_dead)
	{
		if (philo->data->philo_num == 1)
		{
			usleep(philo->data->time_die * 1000);
			yb_print(philo->data, philo->id, "died", 1);
			philo->data->not_dead = 0;
			philo->data->end = 1;
			return (NULL);
		}
		if (yb_get_time() - philo->last_time_eat > philo->data->time_die)
		{
			yb_print(philo->data, philo->id, "died", 1);
			philo->data->not_dead = 0;
			philo->data->end = 1;
			return (NULL);
		}
		if (philo->data->time_eat == (philo->data->must_eat_num * philo->data->philo_num))
		{
			philo->data->not_dead = 0;
			philo->data->end = 1;
			return (NULL);
		}
		usleep(200);
	}
	return (NULL);
}