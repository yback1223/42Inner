/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:32:13 by yback             #+#    #+#             */
/*   Updated: 2023/01/25 09:42:33 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

float	my_pow(int decimal_places)
{
	int		i;
	float	result;
	
	i = 0;
	result = 1;
	while (decimal_places != i)
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


float	ft_strtod(char *str, int decimal_found, int decimal_places)
{
	int		sign;
	float	result;
	
	sign = 1;
	str += what_sign(str, &sign);
	while (*str)
	{
		if (!(('0' <= *str && *str <= '9') || *str == '.'))
			exit(1);
		if (*str == '.')
		{
			if (decimal_found == 1)
				exit(1);
			str++;
			decimal_found = 1;
			continue;
		}
		if (!decimal_found)
			result = result * 10 + (*str - '0');
		else
			result = result + ((float)(*str - '0') / my_pow(++decimal_places));
		str++;
	}
	return result * sign;
}