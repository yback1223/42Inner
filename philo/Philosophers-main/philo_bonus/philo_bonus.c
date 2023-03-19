/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:52:13 by yback             #+#    #+#             */
/*   Updated: 2023/03/16 21:52:14 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	ft_get_time(void)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	return (ct.tv_sec * 1000LL + ct.tv_usec / 1000);
}

void	create_philo(t_data *data)
{
	data->i = 0;
	data->time_var = ft_get_time();
	while (data->i < data->nb)
	{
		data->philos[data->i]->last_meal = ft_get_time();
		data->philos[data->i]->forked = fork();
		if (data->philos[data->i]->forked == 0)
		{
			pthread_create(&data->philos[data->i]->overseer, NULL,
				&monitor, (void *)data->philos[data->i]);
			philo_routine((void *)data->philos[data->i]);
		}
		usleep(100);
		data->i++;
	}
	end_philo(data);
}

void	ft_set_data(int argc, char *argv[], t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		data->nb = ft_atoi(argv[1]);
		data->t_die = ft_atoi(argv[2]);
		data->t_eat = ft_atoi(argv[3]);
		data->t_sleep = ft_atoi(argv[4]);
		if (data->t_eat <= 60 || data->t_sleep <= 60 || data->nb >= 200)
			ft_error_handler();
		data->not_dead = 1;
		data->nb_me = -42;
		if (argc == 6)
			data->nb_me = ft_atoi(argv[5]);
		data->forks = init_forks(data);
		if (!data->forks)
			ft_error_handler();
		data->philos = init_philos(data);
		if (!data->philos)
			ft_error_handler();
		create_philo(data);
	}
	else
		ft_error_handler();
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	memset(data, 0, sizeof(t_data));
	ft_set_data(argc, argv, data);
	exit(1);
}
