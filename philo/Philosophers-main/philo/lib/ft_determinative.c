/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determinative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:51:14 by yback             #+#    #+#             */
/*   Updated: 2023/03/16 21:52:37 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*init_forks(t_data *data)
{
	unsigned int	i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nb);
	if (!forks)
		return (NULL);
	while (i < data->nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	**init_philos(t_data *data)
{
	unsigned int	i;
	t_philo			**philos;

	i = 0;
	philos = malloc(sizeof(t_philo *) * data->nb);
	if (!philos)
		return (NULL);
	while (i < data->nb)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (NULL);
		pthread_mutex_init(&philos[i]->eating, NULL);
		philos[i]->id = i + 1;
		philos[i]->fork = i;
		philos[i]->next_fork = (i + 1) % data->nb;
		philos[i]->data = data;
		i++;
	}
	philos[i] = NULL;
	return (philos);
}
