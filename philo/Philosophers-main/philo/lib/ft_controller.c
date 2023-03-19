/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:51:12 by yback             #+#    #+#             */
/*   Updated: 2023/03/16 21:52:38 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_get_time(void)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	return (ct.tv_sec * 1000LL + ct.tv_usec / 1000);
}

void	*philo_routine(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	while (ph->data->not_dead)
	{
		philo_eating(ph);
		philo_sleeping(ph);
		philo_thinking(ph);
		usleep(190);
	}
	return (NULL);
}

void	*monitor(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	while (ph->data->not_dead)
	{
		if (ph->data->nb == 1)
		{
			usleep(ph->data->t_die * 1000);
			ft_print(ph->data, ph->id, "\033[0;31mdied\033[0m", 1);
			ph->data->not_dead = 0;
			ph->data->end = 1;
			return (NULL);
		}
		if (ft_get_time() - ph->last_meal > ph->data->t_die)
		{
			ft_print(ph->data, ph->id, "\033[0;31mdied\033[0m", 1);
			ph->data->not_dead = 0;
			ph->data->end = 1;
			return (NULL);
		}
		if (ph->data->eat_time == (ph->data->nb_me * ph->data->nb))
		{
			ph->data->not_dead = 0;
			ph->data->end = 1;
			return (NULL);
		}
		usleep(190);
	}
	return (NULL);
}
