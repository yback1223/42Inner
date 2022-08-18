/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:29:33 by youjeon           #+#    #+#             */
/*   Updated: 2022/08/18 16:40:20 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

char	*ft_strchr(const char *str, int c)
{
	char	*ptr_str;
	char	to_find;

	ptr_str = (char *)str;
	to_find = (char)c;
	while (*ptr_str)
	{
		if (*ptr_str == to_find)
			return (ptr_str);
		else
			ptr_str++;
	}
	if (to_find == '\0')
		return (ptr_str);
	return (NULL);
}

void	init_info(t_info *info)
{
	info->hash = -1;
	info->minus = -1;
	info->period = -1;
	info->plus = -1;
	info->space = -1;
	info->type = -1;
	info->zero = -1;
	info->width = 0;
	info->precision = 0;
}

int	info_get_zero(t_info *info, int i)
{
	if (info->period > -1)
		info->precision = info->precision * 10;
	else if (info->width)
		info->width = info->width * 10;
	else
		info->zero = i;
	return (1);
}

int	set_info(t_info *info, char *arr, int i)
{
	if (ft_strchr("0", arr[i]))
		return (info_get_zero(info, i));
	if (ft_strchr("-.# +", arr[i]))
	{
		if (arr[i] == '-')
			info->minus = i;
		else if (arr[i] == '.')
			info->period = i;
		else if (arr[i] == '#')
			info->hash = i;
		else if (arr[i] == ' ')
			info->space = i;
		else if (arr[i] == '+')
			info->plus = i;
		return (1);
	}
	if (ft_strchr("123456789", arr[i]))
	{
		if (info->period > -1)
			info->precision = (info->precision * 10) + (arr[i] - '0');
		else
			info->width = (info->width * 10) + (arr[i] - '0');
		return (1);
	}
	return (0);
}