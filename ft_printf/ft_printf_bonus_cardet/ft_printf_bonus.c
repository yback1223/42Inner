/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:46:24 by youjeon           #+#    #+#             */
/*   Updated: 2022/08/18 16:55:13 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_whichformat(t_info *info, va_list ap)
{
	int	total_length;

	total_length = 0;
	if (info->type == '%')
		total_length = print_percent(info);
	else if (info->type == 'd' || info->type == 'i')
		total_length = print_di(info, ap);
	else if (info->type == 'u')
		total_length = print_u(info, ap);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		total_length = print_xX(info, ap);
	else if (info->type == 'c')
		total_length = print_c(info, ap);
	else if (info->type == 's')
		total_length = print_s(info, ap);
	return (total_length);
}

int	init_parsing(char *arr, int *i, va_list ap)
{
	t_info	*info;
	int		total_length;

	total_length = 0;
	(*i)++;
	info = malloc(sizeof(t_info));
	init_info(info);
	while (ft_strchr("-0.# +123456789", arr[*i]))
	{
		set_info(info, arr, *i);
		(*i)++;
	}
	if (ft_strchr("cspdiuxX%", arr[*i]))
	{
		info->type = arr[*i];
		total_length += ft_whichformat(info, ap);
	}
	ft_free(info);
	return (total_length);
}

int	ft_printf(const char *arr, ...)
{
	va_list	ap;
	int		total_length;
	int		i;

	i = 0;
	total_length = 0;
	va_start(ap, arr);
	while (arr[i])
	{
		if (arr[i] == '%')
		{
			total_length += init_parsing(arr, &i, ap);
		}
		else
		{
			write(1, &arr[i], 1);
			total_length++;
		}
		i++;
	}
	va_end(ap);
	return (total_length);
}