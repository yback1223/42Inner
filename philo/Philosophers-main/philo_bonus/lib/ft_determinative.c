/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determinative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:51:54 by yback             #+#    #+#             */
/*   Updated: 2023/03/16 21:51:55 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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
		sem_unlink("/eating");
		philos[i]->eating = sem_open("/eating", 512 | 2048, 256 | 128, 1);
		philos[i]->id = i + 1;
		philos[i]->data = data;
		i++;
	}
	return (philos);
}

sem_t	*init_forks(t_data *data)
{
	sem_t			*forks;
	unsigned int	i;

	i = 0;
	forks = NULL;
	sem_unlink("/forks");
	forks = sem_open("/forks", 512 | 2048, 256 | 128, data->nb);
	sem_unlink("/print");
	data->print = sem_open("/print", 512 | 2048, 256 | 128, 1);
	return (forks);
}

void	end_philo(t_data *data)
{
	unsigned int	i;
	unsigned int	x;
	int				stat_loc;

	i = 0;
	while (i < data->nb)
	{
			x = 0;
		waitpid(-1, &stat_loc, 0);
		if (WEXITSTATUS(stat_loc))
		{
			while (x < data->nb)
				kill(data->philos[x++]->forked, SIGKILL);
			sem_close(data->philos[i]->eating);
			pthread_detach(data->philos[i]->overseer);
			free(data->philos[i]);
		}
		sem_close(data->print);
		sem_close(data->forks);
		i++;
	}
	free(data->philos);
	free(data);
}
