/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_behaviours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:51:07 by yback             #+#    #+#             */
/*   Updated: 2023/03/16 21:52:39 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_data *data, int pid, char *str, int isdead)
{
	isdead = 0;
	pthread_mutex_lock(&data->print);
	if (!data->end)
		printf("%lld %d %s\n", ft_get_time() - data->time_var, pid, str);
	if (!isdead)
		pthread_mutex_unlock(&data->print);
	pthread_mutex_unlock(&data->print);

}

void	philo_thinking(t_philo *ph)
{
	ft_print(ph->data, ph->id, "is thinking", 0);
}

void	philo_eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->forks[ph->fork]);
	ft_print(ph->data, ph->id, "has taken a fork", 0);
	pthread_mutex_lock(&ph->data->forks[ph->next_fork]);
	ft_print(ph->data, ph->id, "has taken a fork", 0);
	pthread_mutex_lock(&ph->eating);
	ft_print(ph->data, ph->id, "is eating", 0);
	ph->data->eat_time++;
	ph->eating_state = 1;
	ph->last_meal = ft_get_time();
	if (ph->data->t_eat > 0)
		usleep(ph->data->t_eat * 1000);
	ph->eating_state = 0;
	pthread_mutex_unlock(&ph->eating);
	pthread_mutex_unlock(&ph->data->forks[ph->fork]);
	pthread_mutex_unlock(&ph->data->forks[ph->next_fork]);
}

void	philo_sleeping(t_philo *ph)
{
	ph->last_sleep = ft_get_time();
	ft_print(ph->data, ph->id, "is sleeping", 0);
	if (ph->data->t_sleep > 0)
		usleep(ph->data->t_sleep * 1000);
	while (ph->last_sleep + ph->data->t_sleep > ft_get_time())
		continue ;
}
