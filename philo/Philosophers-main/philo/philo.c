/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:51:32 by yback             #+#    #+#             */
/*   Updated: 2023/03/17 09:39:23 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_data *data)
{
	data->i = 0;
	data->time_var = ft_get_time();
	while (data->i < data->nb)
	{
		data->philos[data->i]->last_meal = ft_get_time();
		pthread_create(&data->philos[data->i]->controller, NULL,
			&philo_routine, (void *)data->philos[data->i]);
		usleep(100);
		data->i++;
	}
	data->i = 0;
	while (data->i < data->nb)
	{
		pthread_create(&data->philos[data->i]->overseer, NULL,
			&monitor, (void *)data->philos[data->i]);
		usleep(190);
		data->i++;
	}
	while (data->not_dead != 0)
		usleep(190);
}

void	free_philo(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb)
	{
		pthread_mutex_destroy(&data->philos[i]->eating);
		pthread_detach(data->philos[i]->controller);
		pthread_detach(data->philos[i]->overseer);
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
	free(data->forks);
	free(data);
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
	free_philo(data);
	//system("leaks philo");
	return (0);
}
