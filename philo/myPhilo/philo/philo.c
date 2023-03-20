/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:45:10 by yback             #+#    #+#             */
/*   Updated: 2023/03/19 19:46:25 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->philos[i]->eating);
		pthread_detach(data->philos[i]->thread_storage);
		pthread_detach(data->philos[i]->overseer);
		free(data->philos[i++]);
	}
	free(data->philos);
	free(data->forks);
	free(data);
}

void	create_philo(t_data *data)
{
	data->one_philo = 0;
	data->time_var = yb_get_time();
	while (data->one_philo < data->philo_num)
	{
		data->philos[data->one_philo]->last_time_eat = yb_get_time();
		pthread_create(&data->philos[data->one_philo]->thread_storage, NULL,
			&philo_routine, (void *)data->philos[data->one_philo]);
		usleep(200);
		data->one_philo++;
	}
	data->one_philo = 0;
	while (data->one_philo < data->philo_num)
	{
		pthread_create(&data->philos[data->one_philo]->overseer, NULL,
			&monitor, (void *)data->philos[data->one_philo]);
		usleep(200);
		data->one_philo++;
	}
	while (data->not_dead != 0)
		usleep(200);
	// free(data->time_var);
}

void	yb_set_data(int ac, char **av, t_data *data)
{
	if (ac == 5 || ac == 6)
	{
		data->philo_num = yb_atoi(av[1]);
		data->time_die = yb_atoi(av[2]);
		data->time_eat = yb_atoi(av[3]);
		data->time_sleep = yb_atoi(av[4]);
		if (data->time_eat <= 0 || data->time_sleep < 0 || data->time_die < 0 || data->philo_num < 0)
			yb_error_handler();
		data->not_dead = 1;
		data->must_eat_num = -1;
		if (ac == 6)
			data->must_eat_num = yb_atoi(av[5]);
		data->forks = init_forks(data);
		if (!data->forks)
			yb_error_handler();
		data->philos = init_philos(data);
		if (!data->philos)
			yb_error_handler();
		create_philo(data);
	}
	else
		yb_error_handler();;
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	memset(data, 0, sizeof(t_data));
	yb_set_data(ac, av, data);
	free_philos(data);
	system("leaks philo");
	return (0);
}