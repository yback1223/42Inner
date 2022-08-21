/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:51:54 by yback             #+#    #+#             */
/*   Updated: 2022/08/21 15:20:55 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_write(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_atoi(char *arr)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (arr[i])
		res = (res * 10) + (arr[i++] - '0');
	return (res);
}

int	ft_strnlen(char *str, int max)
{
	int i;

	i = 0;
	while (str[i] && i < max)
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_div_mod(long *tmpnum, int base)
{
	char	digit[16] = "0123456789ABCDEF";
	int		index;

	index = *tmpnum % base;
	*tmpnum /= base;
	return (digit[index]);
}
