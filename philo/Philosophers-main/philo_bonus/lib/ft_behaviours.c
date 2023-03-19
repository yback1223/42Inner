/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_behaviours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:51:46 by yback             #+#    #+#             */
/*   Updated: 2023/03/16 21:51:47 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_print(t_data *data, int pid, char *str, int isdead)
{
	sem_wait(data->print);
	printf("%lld %d %s\n", ft_get_time() - data->time_var, pid, str);
	if (!isdead)
		sem_post(data->print);
	else
		exit(1);
}

void	philo_thinking(t_philo *ph)
{
	ft_print(ph->data, ph->id, "is thinking", 0);
}

void	philo_eating(t_philo *ph)
{
	sem_wait(ph->data->forks);
	ft_print(ph->data, ph->id, "has taken a fork", 0);
	sem_wait(ph->data->forks);
	ft_print(ph->data, ph->id, "has taken a fork", 0);
	sem_wait(ph->eating);
	ft_print(ph->data, ph->id, "is eating", 0);
	ph->last_meal = ft_get_time();
	ph->data->eat_time++;
	usleep(ph->data->t_eat * 1000);
	while (ft_get_time() - ph->last_meal < ph->data->t_eat)
		continue ;
	sem_post(ph->eating);
	sem_post(ph->data->forks);
	usleep(100);
}

void	philo_sleeping(t_philo *ph)
{
	ph->last_sleep = ft_get_time();
	ft_print(ph->data, ph->id, "is sleeping", 0);
	usleep(ph->data->t_sleep * 1000);
	while (ft_get_time() - ph->last_sleep < ph->data->t_sleep)
		continue ;
	usleep(100);
}
