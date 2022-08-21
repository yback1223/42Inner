/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:23:47 by yback             #+#    #+#             */
/*   Updated: 2022/08/21 16:54:14 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

void	cook_specifier(info_t *info, const char *fmt, int i, va_list ap)
{
	if (fmt[i] == 'c')
		cook_c(info, ap);
	else if (fmt[i] == 's')
		cook_s(info, ap);
	else if (fmt[i] == 'p')
		cook_p(info, ap);
	else if (fmt[i] == '%')
		info->str[info->i_for_str] = '%';
	else if (fmt[i] == 'x')
	{
		info->small = 1;
		cook_xx(info, ap);
	}
	else if (fmt[i] == 'X')
		cook_xx(info, ap);
	else if (fmt[i] == 'i' || fmt[i] == 'd')
		cook_di(info, ap);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	info_t	info;

	i = 0;
	init_info(&info);
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
			info.str[info.i_for_str] = fmt[i];
		else
		{
			i++;
			i = cook_info(&info, fmt, i);
			cook_specifier(&info, fmt, i, ap);
		}
		i++;
	}
	va_end(ap);
	i = 0;
	while (info.str[i])
		ft_write(info.str[i++]);
	return (i);
}
