/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:32:13 by yback             #+#    #+#             */
/*   Updated: 2023/01/30 16:46:36 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

float	my_pow(int place)
{
	int		i;
	float	result;

	i = 0;
	result = 1;
	while (place != i)
	{
		result *= 10;
		i++;
	}
	return (result);
}

int	what_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	return (i);
}

float	ft_strtod(char *str, int decimal_found, int place, float result)
{
	int		sign;
	int		i;

	result = 0;
	i = what_sign(str, &sign);
	while (str[i])
	{
		if (!(('0' <= str[i] && str[i] <= '9') || str[i] == '.'))
			exit(1);
		if (str[i] == '.')
		{
			if (decimal_found == 1)
				exit(1);
			i++;
			decimal_found = 1;
			continue ;
		}
		if (!decimal_found)
			result = result * 10 + (str[i] - '0');
		else
			result = result + ((str[i] - '0') / my_pow(++place));
		i++;
	}
	return (result * sign);
}
