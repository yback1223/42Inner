/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cook_cspdixx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:54:28 by yback             #+#    #+#             */
/*   Updated: 2022/08/21 15:17:07 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

void	cook_di(info_t *info, va_list ap)
{
	long	num;
	int		size;
	char	sign;

	info->base = 10;
	info->sign = 1;
	size = info->width;
	if (info->left == 1)
		info->zeropad = -1;
	num = va_arg(ap, int);
	sign = checking_sign(info, &num, &size);
	checking_special(info, &size);
	checking_num_first(info, num, sign, &size);
}

void	cook_xx(info_t *info, va_list ap)
{
	long	num;
	int		size;
	char	sign;

	info->base = 16;
	info->sign = 1;
	size = info->width;
	if (info->left == 1)
		info->zeropad = -1;
	num = va_arg(ap, unsigned int);
	sign = checking_sign(info, &num, &size);
	checking_special(info, &size);
	checking_num_first(info, num, sign, &size);
}

void	cook_p(info_t *info, va_list ap)
{
	char	sign;
	int		size;
	long	num;

	info->base = 16;
	size = info->width;
	if (info->left == 1)
		info->zeropad = -1;
	num = (unsigned long)va_arg(ap, void *);
	sign = checking_sign(info, &num, &size);
	checking_special(info, &size);
	checking_num_first(info, num, sign, &size);
}

void	cook_c(info_t *info, va_list ap)
{
	if (info->left == -1)
		while (--info->width > 0)
			info->str[info->i_for_str++] = ' ';
	info->str[info->i_for_str++] = (unsigned char)va_arg(ap, int);
	while (--info->width > 0)
			info->str[info->i_for_str++] = ' ';
}

void	cook_s(info_t *info, va_list ap)
{
	char	*newarr;
	int		len;
	int		j;

	j = 0;
	newarr = va_arg(ap, char *);
	len = ft_strnlen(newarr, info->precision);
	if (info->left != 1)
		while (info->width-- > len)
			info->str[info->i_for_str++] = ' ';
	while (j < len)
		info->str[info->i_for_str++] = newarr[j++];
	while (len < info->precision--)
		info->str[info->i_for_str++] = ' ';
}