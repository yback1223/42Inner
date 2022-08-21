/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:56:45 by yback             #+#    #+#             */
/*   Updated: 2022/08/21 15:15:55 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	checking_sign(info_t *info, long *num, int *size)
{
	if (info->sign == 1)
	{
		if (*num < 0)
		{
			*num *= -1;
			*size -= 1;
			return ('-');
		}
		else if (info->plus == 1)
		{
			*size -= 1;
			return ('+');
		}
		else if (info->space == 1)
		{
			*size -= 1;
			return (' ');
		}
	}
	return (0);
}

void	checking_special(info_t *info, int *size)
{
	if (info->special == 1)
	{
		if (info->base == 16)
			*size -= 2;
	}
}

void	checking_num_second(info_t *info, int *size)
{
	if (info->special == 1)
	{
		if (info->base == 16)
		{
			info->str[info->i_for_str++] = '0';
			if (info->small == 1)
				info->str[info->i_for_str++] = 'x';
			else if (info->small == -1)
				info->str[info->i_for_str++] = 'X';
		}
	}
	if (info->left == -1)
	{
		if (info->zeropad == 1)
			while (*size-- > 0)
				info->str[info->i_for_str++] = '0';
		else if (info->space == 1)
			while (*size-- > 0)
				info->str[info->i_for_str++] = ' ';
	}
}

void	checking_num_first(info_t *info, long num, char sign, int *size)
{	
	char	arr[1024];
	int		i;

	i = 0;
	if (num == 0)
		arr[i++] = 0;
	else
		while (num != 0)
			arr[i++] = ft_div_mod(&num, info->base);
	if (i > info->precision)
		info->precision = i;
	*size -= info->precision;
	if (info->zeropad == -1 && info->left == -1)
		while (*size-- > 0)
			info->str[info->i_for_str++] = ' ';
	if (sign)
		info->str[info->i_for_str++] = sign;
	checking_num_second(info, size);
	while (i < info->precision--)
		info->str[info->i_for_str] = '0';
	while (i-- > 0)
		info->str[info->i_for_str++] = arr[i];
	info->str[info->i_for_str++] = 0;
	while (*size-- > 0)
		info->str[info->i_for_str++] = ' ';
}
