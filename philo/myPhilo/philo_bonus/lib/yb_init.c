/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:24:49 by yback             #+#    #+#             */
/*   Updated: 2023/03/18 19:29:53 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_philo	**init_philo(t_data *data)
{
	unsigned int	i;
	t_philo			**philos;

	i = 0;
	philos = (t_philo **)malloc(sizeof(t_philo *) * data->philo_num);
	if (!philos)
		return (NULL);
	while (i < data->philo_num)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (NULL);
		sem_unlink("/eating");
		philos[i]->eating = sem_open("/eating", 512 | 2048, 256 | 128, 1);
		philos[i]->id = i + 1;
		philos[i++]->data = data;
	}
	return (philos);
}