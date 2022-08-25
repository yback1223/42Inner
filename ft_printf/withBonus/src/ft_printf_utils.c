/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:54:46 by yback             #+#    #+#             */
/*   Updated: 2022/08/25 21:02:58 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char **fmt)
{
	int	i;

	i = 0;
	while (**fmt >= '0' && **fmt <= '9')
		i = i * 10 + *((*fmt)++) - '0';
	return (i);
}

int	ft_div(t_info *info)
{
	int	res;

	res = (unsigned long)info->num % (unsigned int)info->base;
	info->num = (unsigned long)info->num / (unsigned int)info->base;
	return (res);
}

int	ft_strnlen(char *s, int max)
{
	int	i;

	i = 0;
	if (max == 0)
		while (s[i])
			i++;
	else
		while (s[i] && i < max)
			i++;
	return (i);
}

void	init_info(t_info *info, const char **fmt)
{
	info->base = 10;
	info->left = -1;
	info->plus = -1;
	info->precision = 0;
	info->precisionstat = -1;
	info->sign = 0;
	info->small = -1;
	info->space = -1;
	info->special = -1;
	info->width = -1;
	info->zeropad = -1;
	info->fmt = 0;
	info->base = 10;
	info->len = 0;
	info->i = 0;
	info->num = 0;
	(*fmt)++;
}

int	ft_for_i(t_info *info, int i, char **newarr)
{
	if (info->precisionstat == 1)
		**(newarr + i) = 0;
	else
	{
		**(newarr + i) = '0';
		i++;
	}
	return (i);
}
