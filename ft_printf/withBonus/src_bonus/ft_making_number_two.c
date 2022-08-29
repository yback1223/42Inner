/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_making_number_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:57:12 by yback             #+#    #+#             */
/*   Updated: 2022/08/25 20:47:05 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*making_setting_mini_one(t_info *info, char *wow)
{
	info->width--;
	while (info->width > 0)
	{
		info->width--;
		*wow++ = '0';
	}
	while (info->precision > 0)
	{
		info->precision--;
		*wow++ = '0';
	}
	return (wow);
}

char	*making_setting_three(t_info *info, char *wow, char sign, int tmp)
{
	if (info->fmt == '%' && info->left != 1)
		wow = making_setting_mini_one(info, wow);
	while (info->width > 0)
	{
		info->width--;
		*wow++ = ' ';
	}
	if (info->special == -1)
		if (info->sign && sign)
			*wow++ = sign;
	if (info->special == 1)
	{
		if (info->sign && sign)
			*wow++ = sign;
		if (info->base == 16
			&& !((info->fmt == 'x' || info->fmt == 'X') && tmp == 0))
		{
			*wow++ = '0';
			if (info->small == 1)
				*wow++ = 'x';
			else
				*wow++ = 'X';
		}
	}
	return (wow);
}

char	*making_setting_four(t_info *info, char *wow, char sign, int tmp)
{
	if (info->special == -1)
		if (info->sign && sign)
			*wow++ = sign;
	if (info->special == 1)
	{
		if (info->sign && sign)
			*wow++ = sign;
		if (info->base == 16
			&& !((info->fmt == 'x' || info->fmt == 'X') && tmp == 0))
		{
			*wow++ = '0';
			if (info->small == 1)
				*wow++ = 'x';
			else
				*wow++ = 'X';
		}
	}
	return (wow);
}

char	*finish_part(t_info *info, int i, char *wow, char *newarr)
{
	while (i < info->precision)
	{
		*wow++ = '0';
		info->precision--;
	}
	while (i > 0)
	{
		i--;
		*wow++ = newarr[i];
	}
	while (info->width > 0)
	{
		info->width--;
		*wow++ = ' ';
	}
	free(newarr);
	return (wow);
}

void	ft_for_small(t_info *info, char fmt)
{
	if (fmt == '-')
		info->left = 1;
	else if (fmt == '+')
		info->plus = 1;
	else if (fmt == ' ')
		info->space = 1;
	else if (fmt == '#')
		info->special = 1;
	else if (fmt == '0')
		info->zeropad = 1;
}
