/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:04:07 by yback             #+#    #+#             */
/*   Updated: 2022/12/27 14:48:36 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	compare_command(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (*(str1 + i) && *(str1 + i) == *(str2 + i))
		i++;
	return (*((unsigned char *)str1 + i) - *((unsigned char *)str2 + i));
}

void	print_error(int err)
{
	if (err == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (err == 2)
	{
		ft_putstr_fd("command error\n", 2);
		exit(1);
	}
}

int	check_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		free(str[i++]);
	free(str);
}
