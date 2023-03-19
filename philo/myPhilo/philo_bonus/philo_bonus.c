/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:14:59 by yback             #+#    #+#             */
/*   Updated: 2023/03/18 19:23:52 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	exit(1);
}