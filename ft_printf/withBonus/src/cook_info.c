/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cook_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:49:57 by yback             #+#    #+#             */
/*   Updated: 2022/08/21 14:02:43 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(info_t *info)
{
	int	i;

	i = 0;
	info->left = -1;
	info->plus = -1;
	info->sign = -1;
	info->small = -1;
	info->space = -1;
	info->special = -1;
	info->zeropad = -1;
	info->width = 0;
	info->precision = 0;
	info->i_for_str = 0;
	while (info->str[i])
		info->str[i] = 0;
}

int	cook_flags(info_t *info, const char *fmt, int j)
{
	while (fmt[j] == '-' || fmt[j] == '+' || fmt[j] == ' ' || fmt[j] == '#' || fmt[j] == '0')
	{
		if (fmt[j] == '-')
			info->left = 1;
		else if (fmt[j] == '+')
			info->plus = 1;
		else if (fmt[j] == ' ')
			info->space = 1;
		else if (fmt[j] == '#')
			info->special = 1;
		else if (fmt[j] == '0')
			info->zeropad = 1;
		j++;
	}
	return (j);
}

int	cook_width(info_t *info, const char *fmt, int j)
{
	char	width[10];
	int		k;

	k = 0;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		width[k++] = fmt[j++];
	width[k] = '\0';
	if (k > 0)
		info->width = ft_atoi(width);
	return (j);
}

int	cook_precision(info_t *info, const char *fmt, int j)
{
	char	prec[10];
	int		k;

	k = 0;
	if (fmt[j] == '.')
	{
		j++;
		while (fmt[j] >= '0' && fmt[j] <= '9')
			prec[k++] = fmt[j++];
		prec[k] = '\0';
		if (k > 0)
			info->precision = ft_atoi(prec);
	}
	return (j);
}

int	cook_info(info_t *info, const char *fmt, int i)
{
	i = cook_flags(info, fmt, i);
	i = cook_width(info, fmt, i);
	i = cook_precision(info, fmt, i);
	return (i);
}