/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:58:05 by yback             #+#    #+#             */
/*   Updated: 2022/08/29 20:00:13 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

char	*number(t_info *info, char *wow)
{
	char	sign;
	char	*newarr;
	int		i;
	long	tmp;
	int		w;

	w = info->width;
	i = 0;
	tmp = info->num;
	sign = 0;
	if (info->left == 1)
		info->zeropad = -1;
	if (info->base < 2 || info->base > 16)
		return (0);
	making_sign_and_spe(info, &sign, tmp);
	newarr = making_newarr(info, &i);
	wow = making_setting_one(info, &i, wow);
	if (info->left != 1 && info->zeropad == 1 && info->precisionstat == -1)
		wow = making_setting_two(info, sign, wow, tmp);
	else if (info->left != 1 && info->zeropad == 1 && w > info->precision)
		wow = making_setting_three(info, wow, sign, tmp);
	else
		wow = making_setting_four(info, wow, sign, tmp);
	wow = finish_part(info, i, wow, newarr);
	return (wow);
}

char	*ft_spec_intx(t_info *info, const char **fmt, va_list ap, char *wow)
{
	if (**fmt == 'c' || **fmt == 's')
		wow = ft_for_sc(info, &(*fmt), wow, ap);
	else if (**fmt == 'p' || **fmt == '%' || **fmt != 'u')
		wow = ft_w_con(info, &(*fmt), wow, ap);
	(*fmt)++;
	return (wow);
}

int	ft_main_pri(char *buf, const char *fmt, va_list ap, t_info *info)
{
	char	*wow;

	wow = buf;
	while (*fmt)
	{
		if (*fmt != '%' && *fmt)
		{
			*wow++ = *fmt++;
			continue ;
		}
		init_info(info, &fmt);
		ft_for_flags(info, &fmt);
		if (*fmt == 'x' || *fmt == 'X' || *fmt == 'd'
			|| *fmt == 'i' || *fmt == 'u')
			wow = ft_wo_con(info, &fmt, ap, wow);
		else
		{
			wow = ft_spec_intx(info, &fmt, ap, wow);
			continue ;
		}
		fmt++;
	}
	*wow = '\0';
	return (wow - buf);
}

int	ft_printf(const char *fmt, ...)
{
	char	arr[1000000];
	va_list	ap;
	t_info	info;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_start(ap, fmt);
	i = ft_main_pri(arr, fmt, ap, &info);
	va_end(ap);
	while (j < i)
	{
		if (write(1, &arr[j++], 1) == -1)
			return (-1);
	}
	return (i);
}
