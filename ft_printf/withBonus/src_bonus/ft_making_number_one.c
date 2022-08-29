/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_making_number_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:56:08 by yback             #+#    #+#             */
/*   Updated: 2022/08/25 21:02:52 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	making_sign_and_spe(t_info *info, char *sign, int tmp)
{
	if (info->num < 0 && info->sign == 1)
	{
		*sign = '-';
		info->num *= -1;
		info->width--;
	}
	else if (info->plus == 1 && info->sign == 1)
	{
		*sign = '+';
		info->width--;
	}
	else if (info->space == 1 && info->sign == 1)
	{
		*sign = ' ';
		info->width--;
	}
	if (info->special == 1)
	{
		if (info->base == 16 && tmp == 0x0 && info->fmt == 'p')
			info->width -= 2;
		else if (info->base == 16 && tmp != 0)
			info->width -= 2;
	}
}

char	*making_newarr(t_info *info, int *i)
{
	char	*newarr;

	newarr = (char *)malloc(100);
	if (info->num == 0)
		*i = ft_for_i(info, *i, &newarr);
	else if (info->num == '%')
		newarr[(*i)++] = '%';
	else
	{
		while (info->num != 0)
		{
			if (info->small == 1)
			{
				newarr[*i] = "0123456789ABCDEF"[ft_div(info)];
				if (newarr[*i] >= 'A' && newarr[*i] <= 'F')
					newarr[*i] += ('a' - 'A');
				(*i)++;
			}
			else
				newarr[(*i)++] = "0123456789ABCDEF"[ft_div(info)];
		}
	}
	return (newarr);
}

char	*making_setting_one(t_info *info, int *i, char *wow)
{
	if (*i > info->precision)
		info->precision = *i;
	info->width -= info->precision;
	if (info->zeropad != 1 && info->left != 1)
	{
		while (info->width > 0)
		{
			*wow++ = ' ';
			info->width--;
		}
	}
	return (wow);
}

char	*making_setting_two(t_info *info, char sign, char *wow, int tmp)
{
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
	if (info->special == -1)
		if (info->sign && sign)
			*wow++ = sign;
	while (info->width > 0)
	{
		info->width--;
		*wow++ = '0';
	}
	return (wow);
}
