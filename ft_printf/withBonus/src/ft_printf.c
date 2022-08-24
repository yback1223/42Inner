/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:58:05 by yback             #+#    #+#             */
/*   Updated: 2022/08/24 19:57:38 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
	int		precisionstat;
	char	*str;
	int		base;
	char	fmt;
}	info_t;

int	ft_atoi(const char **fmt)
{
	int		i;

	i = 0;
	while (**fmt >= '0' && **fmt <= '9')
		i = i * 10 + *((*fmt)++) - '0';
	return (i);
}

int	ft_div(long *n, int base)
{
	int	res;

	res = (unsigned long)*n % (unsigned int)base;
	*n = (unsigned long)*n / (unsigned int)base;
	return (res);
}

int	ft_strnlen(char *s, int max)
{
	int	i;

	i = 0;
	if (max == 0)
		while (s[i])
			i++;
	else
		while (s[i] && i < max)
			i++;
	return (i);
}

void	init_info(info_t *info)
{
	info->base = 10;
	info->left = -1;
	info->plus = -1;
	info->precision = 0;
	info->precisionstat = -1;
	info->sign = 0;
	info->small = -1;
	info->space = -1;
	info->special = -1;
	info->width = -1;
	info->zeropad = -1;
	info->fmt = 0;
	info->base = 10;
}

char	*number(info_t *info, long num, char *wow)
{
	char	sign;
	char	newarr[100];
	int		i;
	int		tmp;
	int		tmpwidth;

	tmp = num;
	tmpwidth = info->width;
	sign = 0;
	if (info->left == 1)
		info->zeropad = -1;
	if (info->base < 2 || info->base > 16)
		return (NULL);
	if (info->sign == 1)
	{
		if (num < 0)
		{
			sign = '-';
			num *= -1;
			info->width--;
		}
		else if (info->plus == 1)
		{
			sign = '+';
			info->width--;
		}
		else if (info->space == 1)
		{
			sign = ' ';
			info->width--;
		}
	}
	if (info->special == 1)
	{
		if (info->base == 16 && tmp == 0x0 && info->fmt == 'p')
			info->width -= 2;
		else if (info->base == 16 && tmp != 0)
			info->width -= 2;
	}
	i = 0;
	if (num == 0)
	{
		if (info->precisionstat == 1)
			newarr[i] = 0;
		else
			newarr[i++] = '0';
	}
	else if (num == '%')
		newarr[i++] = '%';
	else
		while (num != 0)
		{
			if (info->small == 1)
			{
				newarr[i] = "0123456789ABCDEF"[ft_div(&num, info->base)];
				if (newarr[i] >= 'A' && newarr[i] <= 'F')
					newarr[i] += ('a' - 'A');
				i++;
			}
			else
				newarr[i++] = "0123456789ABCDEF"[ft_div(&num, info->base)];
		}	
	if (i > info->precision)
		info->precision = i;
	info->width -= info->precision;
	if (info->zeropad != 1 && info->left != 1)
		while (info->width > 0)
		{
			*wow++ = ' ';
			info->width--;
		}
	// printf("width = %d, precision = %d\n", info->width, info->precision);
	if (info->left != 1 && info->zeropad == 1 && info->precisionstat == -1)
	{
		if (info->special == 1)
		{
			if (info->sign && sign)
				*wow++ = sign;
			if (info->base == 16 && !((info->fmt == 'x' || info->fmt == 'X') && tmp == 0))
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
	}
	else if (info->left != 1 && info->zeropad == 1 && tmpwidth > info->precision)
	{
		if (info->fmt == '%' && info->left != 1)
		{
			info->width--;
			while (info->width > 0)
			{
				info->width--;
				*wow++ = '0';
			}
			while (info->precision > 0)
			{
				info->precision--;
				*wow++ = '0';
			}
		}
		while (info->width > 0)
		{
			info->width--;
			*wow++ = ' ';
		}
		if (info->special == -1)
			if (info->sign && sign)
				*wow++ = sign;
		if (info->special == 1)
		{
			if (info->sign && sign)
				*wow++ = sign;
			if (info->base == 16 && !((info->fmt == 'x' || info->fmt == 'X') && tmp == 0))
			{
				*wow++ = '0';
				if (info->small == 1)
					*wow++ = 'x';
				else
					*wow++ = 'X';
			}
		}
	}
	else
	{
		if (info->special == -1)
			if (info->sign && sign)
				*wow++ = sign;
		if (info->special == 1)
		{
			if (info->sign && sign)
				*wow++ = sign;
			if (info->base == 16 && !((info->fmt == 'x' || info->fmt == 'X') && tmp == 0))
			{
				*wow++ = '0';
				if (info->small == 1)
					*wow++ = 'x';
				else
					*wow++ = 'X';
			}
		}
	}
	while (i < info->precision)
	{
		*wow++ = '0';
		info->precision--;
	}
	while (i > 0)
	{
		i--;
		*wow++ = newarr[i];
	}
	while (info->width > 0)
	{
		info->width--;
		*wow++ = ' ';
	}
	return (wow);
}

int	ft_vsprintf(char *buf, const char *fmt, va_list ap, info_t *info)
{
	int				len;
	unsigned long	num;
	char			*s;
	int				i;
	char			*wow;
	
	wow = buf;
	while (*fmt)
	{
		// printf("%c\n", *fmt);
		init_info(info);
		if (*fmt != '%' && *fmt)
		{	
			*wow++ = *fmt++;
			continue;
		}
		++fmt;
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
			++fmt;
		}
		if (*fmt >= '0' && *fmt <= '9')
			info->width = ft_atoi(&fmt);
		if (*fmt == '.')
		{
			info->precisionstat = 1;
			fmt++;
			if (*fmt >= '0' && *fmt <= '9')
				info->precision = ft_atoi(&fmt);
			if (info->precision < 0)
				info->precision = 0;
		}
		info->fmt = *fmt;
		if (*fmt == 'c')
		{
			if (info->left == -1)
			{
				info->width--;
				while (info->width > 0)
				{
					*wow++ = ' ';
					info->width--;
				}
			}
			*wow++ = (unsigned char)va_arg(ap, int);
			info->width--;
			while (info->width > 0)
			{
				*wow++ = ' ';
				info->width--;
			}
			fmt++;
			continue;
		}
		else if (*fmt == 's')
		{
			len = 0;
			s = va_arg(ap, char *);
			if (s == 0)
				s = "(null)";
			if (info->precisionstat == 1 && info->precision == 0)
			{
				if (info->width == 0)
					return (0);
			}
			else
				len = ft_strnlen(s, info->precision);
			if (info->left == -1)
			{
				while (len < info->width)
				{
					*wow++ = ' ';
					info->width--;
				}
			}
			i = 0;
			while (i < len)
			{
				*wow++ = *s++;
				i++;
			}
			while (len < info->width)
			{
				*wow++ = ' ';
				info->width--;
			}
			fmt++;
			continue;
		}
		else if (*fmt == 'p')
		{
			info->small = 1;
			info->special = 1;
			info->base = 16;
			wow = number(info, (unsigned long)va_arg(ap, void *), wow);
			fmt++;
			continue;
		}
		else if (*fmt == '%')
		{			
			num = '%';
			wow = number(info, num, wow);
			fmt++;
			continue;
		}
		else if (*fmt == 'x')
		{
			info->small = 1;
			info->base = 16;
		}
		else if (*fmt == 'X')
			info->base = 16;
		else if (*fmt == 'd' || *fmt == 'i')
			info->sign = 1;
		else if (*fmt != 'u')
		{
			*wow++ = '%';
			if (*fmt)
				*wow++ = *fmt;
			fmt++;
			continue;
		}
		if (info->sign == 1)
			num = va_arg(ap, int);
		else
			num = va_arg(ap, unsigned int);
		wow = number(info, num, wow);
		fmt++;
	}
	*wow = '\0';
	return (wow - buf);
}

int ft_printf(const char *fmt, ...)
{
	char	arr[1000000];
	va_list	ap;
	info_t	info;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_start(ap, fmt);
	i = ft_vsprintf(arr, fmt, ap, &info);
	va_end(ap);

	// printf("%s", arr);
	while (j < i)
		printf("%c", arr[j++]);
	return (i);
}

// #define A "^.^/%17s%s^.^/"
// #define B "(null)", 0

// #define A "\\!/%038.4d\\!/"
// #define B 0

// #define A "^.^/%016d^.^/"
// #define B -644797325

// #define A "42%#62.12x42"
// #define B 0

// #define A "!%42p!"
// #define B 0x0

// #define A "\\!/%#4.2x\\!/"
// #define B 0x0

// #define A "42%0#49.40x42"
// #define B 1110709706

// #define A "%05.3%"
// #define B 

// #define A "42%34.42s42"
// #define B NULL

// #define A "%.7s"
// #define B "hello"

// #define A "%.0x"
// #define B 0

// int main(void)
// {
// 	printf("length of printf = %d\n\n", printf(A, B));
// 	printf("length of ft_printf = %d\n\n", ft_printf(A, B));

// 	// printf("length of printf = %d\n\n", printf(A));
// 	// printf("length of ft_printf = %d\n\n", ft_printf(A));
// }