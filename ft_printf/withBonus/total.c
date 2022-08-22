/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:58:05 by yback             #+#    #+#             */
/*   Updated: 2022/08/22 22:01:23 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct info_s
{
	int		zeropad;
	int		sign;
	int		plus;
	int		space;
	int		left;
	int		small;
	int		special;
	int		width;
	int		precision;
	char	*str;
	int		i_for_str;
	int		base;
}	info_t;

int	ft_atoi(char *s)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i])
		res = res * 10 + (s[i] - '0');
	return (res);
}

int	ft_div(unsigned long n, unsigned int base)
{
	int	res;

	res = n % base;
	n = n / base;
	return (res);
}

int	ft_strnlen(char *s, int max)
{
	int	i;

	i = 0;
	while (s[i] && i < max)
		i++;
	return (i);
}

void	init_info(info_t *info)
{
	info->base = 10;
	info->i_for_str = 0;
	info->left = -1;
	info->plus = -1;
	info->precision = -1;
	info->sign = -1;
	info->small = -1;
	info->space = -1;
	info->special = -1;
	info->width = -1;
	info->zeropad = -1;
}

char	*number(info_t *info, long num, int base)
{
	char	*digits;
	char	*newarr;
	char	c;
	int		i;
	
	digits = "0123456789ABCDEF";
	if (info->left == 1 && info->zeropad == 1)
		info->zeropad == -1;
	if (info->left == 1 && info->zeropad == -1)
		info->zeropad == 1;
	if (info->base < 2 || info->base > 16)
		return (NULL);
	if (info->zeropad == 1)
		c = '0';
	else if (info->zeropad == -1)
		c = ' ';
	if (info->sign == 1)
	{
		if (num < 0)
		{
			info->sign = '-';
			num *= -1;
			info->width--;
		}
		else if (info->plus == 1)
		{
			info->sign = '+';
			info->width--;
		}
		else if (info->space == 1)
		{
			info->sign = ' ';
			info->width--;
		}
	}
	if (info->special == 1)
	{
		if (info->base == 16)
			info->width -= 2;
	}
	i = 0;
	if (num == 0)
		newarr[i++] = '0';
	else
		while (num != 0)
		{
			if (info->small == 1)
				newarr[i++] = (digits[ft_div(num, base)] + 'a' -)
		}

}

int	vsprintf(char *buf, const char *fmt, va_list ap, info_t *info)
{
	int				len;
	unsigned long	num;
	char			*s;
	int				i;

	while (*fmt)
	{
		info->str = buf;
		if (*fmt != '%')
		{
			info->str[info->i_for_str++] = *fmt;
			continue;
		}
		init_info(info);
		while (*fmt == '-' || *fmt == '+' || *fmt == ' ' || *fmt == '#' || *fmt == '0')
		{
			if (*fmt == '-')
				info->left = 1;
			else if (*fmt == '+')
				info->plus = 1;
			else if (*fmt == ' ')
				info->space = 1;
			else if (*fmt == '#')
				info->special = 1;
			else if (*fmt == '0')
				info->zeropad = 1;
			fmt++;
		}
		if (*fmt >= 0 && *fmt <= 9)
			info->width = ft_atoi(&fmt);
		if (*fmt == '.')
		{
			fmt++;
			if (*fmt >= 0 && *fmt <= 9)
				info->precision = ft_atoi(&fmt);
		}
		if (*fmt == 'c')
		{
			if (info->left == -1)
				while (--info->width > 0)
					info->str[info->i_for_str++] = ' ';
			info->str[info->i_for_str++] = (unsigned char)va_arg(ap, int);
			while (--info->width > 0)
				info->str[info->i_for_str++] = ' ';
			continue;
		}
		else if (*fmt == 's')
		{
			s = va_arg(ap, char *);
			len = ft_strnlen(s, info->precision);
			if (info->left == -1)
				while (len < info->width--)
					info->str[info->i_for_str++] = ' ';
			while (i < len)
			{
				info->str[info->i_for_str++] = *s++;
				i++;
			}
			while (len < info->width--)
				info->str[info->i_for_str++] = ' ';
			continue;
		}
		else if (*fmt == 'p')
		{
			continue;
		}
		else if (*fmt == '%')
		{
			info->str[info->i_for_str++] = '%';
			continue;
		}
		else if (*fmt == 'x')
		{
			info->small = 1;
			info->base = 16;
		}
		else if (*fmt == 'X')
			info->base = 16;
		else if (*fmt == 'd' && *fmt == 'i')
			info->sign = 1;
		else if (*fmt == 'u')
			;
		if (info->sign == 1)
			num = va_arg(ap, int);
		else
			num = va_arg(ap, unsigned int);
		
	}
}

int printf(const char *fmt, ...)
{
	char	arr[1024];
	va_list	ap;
	int		total_length;
	info_t	info;

	va_start(ap, fmt);
	total_length = vsprintf(arr, fmt, ap, &info);
	va_end(ap);

	write(1, arr, sizeof(arr));
	return (total_length);
}