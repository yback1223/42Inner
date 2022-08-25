/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_making_main_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:59:56 by yback             #+#    #+#             */
/*   Updated: 2022/08/25 20:49:50 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wo_con(t_info *info, const char **fmt, va_list ap, char *wow)
{
	if (**fmt == 'x')
	{
		info->small = 1;
		info->base = 16;
	}
	else if (**fmt == 'X')
		info->base = 16;
	else if (**fmt == 'd' || **fmt == 'i')
		info->sign = 1;
	if (info->sign == 1)
		info->num = va_arg(ap, int);
	else
		info->num = va_arg(ap, unsigned int);
	return (number(info, wow));
}

char	*ft_w_con(t_info *info, const char **fmt, char *wow, va_list ap)
{
	if (**fmt == 'p')
	{
		info->small = 1;
		info->special = 1;
		info->base = 16;
		info->num = (unsigned long)va_arg(ap, void *);
		wow = number(info, wow);
	}
	else if (**fmt == '%')
	{
		info->num = '%';
		wow = number(info, wow);
	}
	else if (**fmt != 'u')
	{
		*wow++ = '%';
		if (**fmt)
			*wow++ = **fmt;
	}
	return (wow);
}

char	*ft_for_sc_mini(t_info *info, char *wow)
{
	if (info->left == -1)
		while (info->len < info->width--)
			*wow++ = ' ';
	while (info->i++ < info->len)
		*wow++ = *info->s++;
	while (info->len < info->width--)
		*wow++ = ' ';
	return (wow);
}

char	*ft_for_sc(t_info *info, const char **fmt, char *wow, va_list ap)
{
	if (**fmt == 'c')
	{
		if (info->left == -1)
			while (--info->width > 0)
				*wow++ = ' ';
		*wow++ = (unsigned char)va_arg(ap, int);
		while (--info->width > 0)
			*wow++ = ' ';
	}
	else if (**fmt == 's')
	{
		info->s = va_arg(ap, char *);
		if (info->s == 0)
			info->s = "(null)";
		if (info->precisionstat == 1 && info->precision == 0
			&& info->width == 0)
			return (0);
		else if (info->precisionstat != 1 || info->precision != 0)
			info->len = ft_strnlen(info->s, info->precision);
		wow = ft_for_sc_mini(info, wow);
	}
	return (wow);
}

void	ft_for_flags(t_info *info, const char **fmt)
{
	while (**fmt == '-' || **fmt == '+' || **fmt == ' '
		|| **fmt == '#' || **fmt == '0')
	{
		ft_for_small(info, **fmt);
		(*fmt)++;
	}
	if (**fmt >= '0' && **fmt <= '9')
		info->width = ft_atoi(&(*fmt));
	if (**fmt == '.')
	{
		info->precisionstat = 1;
		(*fmt)++;
		if (**fmt >= '0' && **fmt <= '9')
			info->precision = ft_atoi(&(*fmt));
		if (info->precision < 0)
			info->precision = 0;
	}
	info->fmt = **fmt;
}
