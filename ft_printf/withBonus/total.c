/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:23:47 by yback             #+#    #+#             */
/*   Updated: 2022/08/21 21:35:56 by yback            ###   ########.fr       */
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
	char	str[1024];
	int		i_for_str;
	int		base;
}	info_t;

void	init_info(info_t *info);
int		cook_flags(info_t *info, const char *fmt, int j);
int		cook_width(info_t *info, const char *fmt, int j);
int		cook_precision(info_t *info, const char *fmt, int j);
int		cook_info(info_t *info, const char *fmt, int i);

int		ft_write(char c);
int		ft_atoi(char *arr);
int		ft_strlen(char *str);
int		ft_strchr(char *s, int c);
char	ft_div_mod(int small, long *tmpnum, int base);

void	cook_di(info_t *info);
void	cook_xx(info_t *info);
void	cook_p(info_t *info, va_list ap);
void	cook_c(info_t *info, va_list ap);
void	cook_s(info_t *info, va_list ap);

char	checking_sign(info_t *info, long *num, int *size);
void	checking_special(info_t *info, int *size);
void	checking_num_second(info_t *info, int *size);
void	checking_num_first(info_t *info, long num, char sign, int *size);

void	cook_specifier(info_t *info, const char *fmt, int i, va_list ap);
int		ft_printf(const char *fmt, ...);


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

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
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

char	ft_div_mod(int small, long *tmpnum, int base)
{
	char	digit[16] = "0123456789ABCDEF";
	int		index;

	index = *tmpnum % base;
	*tmpnum /= base;
	if (small == 1 && index > 9)
		return (digit[index] + 'a' - 'A');
	return (digit[index]);
}


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
			while (*size > 0)
			{
				info->str[info->i_for_str++] = '0';
				*size -= 1;
			}
		else if (info->zeropad != 1)
			while (*size > 0)
			{
				info->str[info->i_for_str++] = ' ';
				*size -= 1;
			}
	}
}

void	checking_num_first(info_t *info, long num, char sign, int *size)
{	
	char	arr[1024];
	int		i;
	int		thesize;

	i = 0;
	thesize = *size;
	if (num == 0)
		arr[i++] = 0;
	else
		while (num != 0)
		{
			arr[i] = ft_div_mod(info->small, &num, info->base);
			i++;
		}
	if (i > info->precision)
		info->precision = i;
	thesize -= info->precision;
	if (info->zeropad == -1 && info->left == -1)
		while (thesize > 0)
		{
			info->str[info->i_for_str++] = ' ';
			thesize--;
		}
	if (sign)
		info->str[info->i_for_str++] = sign;
	checking_num_second(info, &thesize);
	while (i < info->precision)
	{
		info->str[info->i_for_str++] = '0';
		info->precision--;
	}
	while (i > 0)
		info->str[info->i_for_str++] = arr[--i];
	while (thesize > 0)
	{
		info->str[info->i_for_str++] = ' ';
		thesize--;
	}
}

void	cook_di(info_t *info)
{
	info->sign = 1;
}

void	cook_xx(info_t *info)
{
	info->base = 16;
}

void	cook_p(info_t *info, va_list ap)
{
	char	sign;
	int		size;
	long	num;

	info->base = 16;
	info->small = 1;
	if (info->left == 1)
		info->zeropad = -1;
	info->str[info->i_for_str++] = '0';
	info->str[info->i_for_str++] = 'x';
	num = (unsigned long)va_arg(ap, void *);
	sign = checking_sign(info, &num, &size);
	checking_special(info, &size);
	checking_num_first(info, num, sign, &size);
}

void	cook_c(info_t *info, va_list ap)
{
	info->width -= 1;
	if (info->left == -1)
		while (info->width > 0)
		{
			info->str[info->i_for_str++] = ' ';
			info->width -= 1;
		}
	info->str[info->i_for_str++] = (unsigned char)va_arg(ap, int);
	while (info->width-- > 0)
			info->str[info->i_for_str++] = ' ';
}

void	cook_s(info_t *info, va_list ap)
{
	char	*newarr;
	int		len;
	int		j;

	newarr = va_arg(ap, char *);
	if (!newarr)
		newarr = "(null)";
	len = ft_strlen(newarr);
	if (info->precision != 0 && info->precision < len)
		len = info->precision;
	if (info->left == -1)
		while (info->width > len)
		{
			info->str[info->i_for_str++] = ' ';
			info->width--;
		}
	j = 0;
	while (j < len)
		info->str[info->i_for_str++] = newarr[j++];
	while (len < info->width)
	{
		info->str[info->i_for_str++] = ' ';
		info->width--;
	}
}

void	init_info(info_t *info)
{
	info->left = -1;
	info->plus = -1;
	info->sign = -1;
	info->small = -1;
	info->space = -1;
	info->special = -1;
	info->zeropad = -1;
	info->width = 0;
	info->precision = 0;
}

int	cook_flags(info_t *info, const char *fmt, int j)
{
	while (fmt[j] == '-' || fmt[j] == '+' || fmt[j] == ' ' || fmt[j] == '#' || fmt[j] == '0')
	{
		if (fmt[j] == '-')
			info->left = 1;
		else if (fmt[j] == '+')
			info->plus = 1;
		else if (fmt[j] == ' ')
			info->space = 1;
		else if (fmt[j] == '#')
			info->special = 1;
		else if (fmt[j] == '0')
			info->zeropad = 1;
		j++;
	}
	return (j);
}

int	cook_width(info_t *info, const char *fmt, int j)
{
	char	width[20];
	int		k;

	k = 0;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		width[k++] = fmt[j++];
	width[k] = '\0';
	if (k > 0)
		info->width = ft_atoi(width);
	return (j);
}

int	cook_precision(info_t *info, const char *fmt, int j)
{
	char	prec[20];
	int		k;

	k = 0;
	if (fmt[j] == '.')
	{
		j++;
		while (fmt[j] >= '0' && fmt[j] <= '9')
			prec[k++] = fmt[j++];
		prec[k] = '\0';
		if (k > 0)
			info->precision = ft_atoi(prec);
	}
	return (j);
}

int	cook_info(info_t *info, const char *fmt, int i)
{
	i = cook_flags(info, fmt, i);
	i = cook_width(info, fmt, i);
	i = cook_precision(info, fmt, i);
	return (i);
}

void	cook_specifier(info_t *info, const char *fmt, int i, va_list ap)
{
	long	num;
	int		size;
	char	sign;
	
	size = info->width;
	info->base = 10;
	if (info->left == 1)
		info->zeropad = -1;
	if (fmt[i] == 'c')
		cook_c(info, ap);
	else if (fmt[i] == 's')
		cook_s(info, ap);
	else if (fmt[i] == 'p')
		cook_p(info, ap);
	else if (fmt[i] == '%')
	{
		info->str[info->i_for_str++] = '%';
		return ;
	}
	else if (fmt[i] == 'x')
	{
		info->small = 1;
		cook_xx(info);
	}
	else if (fmt[i] == 'X')
		cook_xx(info);
	else if (fmt[i] == 'i' || fmt[i] == 'd')
		cook_di(info);
	else if (fmt[i] != 'u')
		write(1, &fmt[i], 1);
	if (info->sign == 1)
		num = va_arg(ap, int);
	else
		num = va_arg(ap, unsigned int);
	if (fmt[i] == 'd' || fmt[i] == 'i' || fmt[i] == 'x' || fmt[i] == 'X' || fmt[i] == 'u')
	{
		sign = checking_sign(info, &num, &size);
		checking_special(info, &size);
		checking_num_first(info, num, sign, &size);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	info_t	info;

	i = 0;
	info.i_for_str = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		init_info(&info);
		if (fmt[i] != '%')
			info.str[info.i_for_str++] = fmt[i];
		else
		{
			i++;
			i = cook_info(&info, fmt, i);
			cook_specifier(&info, fmt, i, ap);
		}
		i++;
	}
	info.str[info.i_for_str] = '\0';
	va_end(ap);
	i = 0;
	while (info.str[i])
		ft_write(info.str[i++]);
	return (i - 1);
}

#include <stdio.h>

int main(void)
{
	printf("%%d = %d\n", -123456);
	printf("%%i = %i\n", -123456);
	printf("%%u = %u\n", -123456);
	printf("%%c = %c\n", 'd');
	printf("%%s = %s\n", "-123456");
	printf("%%x = %x\n", -123456);
	printf("%%X = %X\n", -123456);
	printf("%%p = %p\n", "-123456");
	printf("%% = %%\n");

	printf("====================\n");

	ft_printf("%%d = %d\n", -123456);
	ft_printf("%%i = %i\n", -123456);
	ft_printf("%%u = %u\n", -123456);
	ft_printf("%%c = %c\n", 'd');
	ft_printf("%%s = %s\n", "-123456");
	ft_printf("%%x = %x\n", -123456);
	ft_printf("%%X = %X\n", -123456);
	ft_printf("%%p = %p\n", "-123456");
	ft_printf("%% = %%\n");

	printf("====================\n");

	printf("%%d = %010d\n", -123456);
	printf("%%i = %010i\n", -123456);
	printf("%%u = %010u\n", -123456);
	printf("%%c = %10c\n", 'x');
	printf("%%s = %10s\n", "-123456");
	printf("%%x = %010x\n", -123456);
	printf("%%X = %010X\n", -123456);
	printf("%%p = %10p\n", "-123456");
	printf("%% = %%\n");

	printf("====================\n");

	ft_printf("%%d = %010d\n", -123456);
	ft_printf("%%i = %010i\n", -123456);
	ft_printf("%%u = %010u\n", -123456);
	ft_printf("%%c = %10c\n", 'x');
	ft_printf("%%s = %10s\n", "-123456");
	ft_printf("%%x = %010x\n", -123456);
	ft_printf("%%X = %010X\n", -123456);
	ft_printf("%%p = %10p\n", "-123456");
	ft_printf("%% = %%\n");

	printf("====================\n");

	printf("%%d = %-10d\n", -123456);
	printf("%%i = %-10i\n", -123456);
	printf("%%u = %-10u\n", -123456);
	printf("%%c = %-10c\n", 'x');
	printf("%%s = %-10s\n", "-123456");
	printf("%%x = %-10x\n", -123456);
	printf("%%X = %-10X\n", -123456);
	printf("%%p = %-10p\n", "-123456");
	printf("%% = %%\n");

	printf("====================\n");

	ft_printf("%%d = %-10d\n", -123456);
	ft_printf("%%i = %-10i\n", -123456);
	ft_printf("%%u = %-10u\n", -123456);
	ft_printf("%%c = %-10c\n", 'x');
	ft_printf("%%s = %-10s\n", "-123456");
	ft_printf("%%x = %-10x\n", -123456);
	ft_printf("%%X = %-10X\n", -123456);
	ft_printf("%%p = %-10p\n", "-123456");
	ft_printf("%% = %%\n");

	printf("====================\n");

	printf("%%d = %-10.8d\n", -123456);
	printf("%%i = %-10.8i\n", -123456);
	printf("%%u = %-10.8u\n", -123456);
	printf("%%c = %-10c\n", 'x');
	printf("%%s = %-10.8s\n", "-123456");
	printf("%%x = %-10.8x\n", -123456);
	printf("%%X = %-10.8X\n", -123456);
	printf("%%p = %-10p\n", "-123456");
	printf("%% = %%\n");

	printf("====================\n");

	ft_printf("%%d = %-10.8d\n", -123456);
	ft_printf("%%i = %-10.8i\n", -123456);
	ft_printf("%%u = %-10.8u\n", -123456);
	ft_printf("%%c = %-10c\n", 'x');
	ft_printf("%%s = %-10.8s\n", "-123456");
	ft_printf("%%x = %-10.8x\n", -123456);
	ft_printf("%%X = %-10.8X\n", -123456);
	ft_printf("%%p = %-10p\n", "-123456");
	ft_printf("%% = %%\n");

	printf("====================\n");

	printf("%%d = % 10d\n", -123456);
	printf("%%i = % 10i\n", -123456);
	printf("%%u = %-10u\n", -123456);
	printf("%%c = %-10c\n", 'x');
	printf("%%s = %-10s\n", "-123456");
	printf("%%x = %-10x\n", -123456);
	printf("%%X = %-10X\n", -123456);
	printf("%%p = %-10p\n", "-123456");
	printf("%% = %%\n");

	printf("====================\n");

	ft_printf("%%d = % 10d\n", -123456);
	ft_printf("%%i = % 10i\n", -123456);
	ft_printf("%%u = %-10u\n", -123456);
	ft_printf("%%c = %-10c\n", 'x');
	ft_printf("%%s = %-10s\n", "-123456");
	ft_printf("%%x = %-10x\n", -123456);
	ft_printf("%%X = %-10X\n", -123456);
	ft_printf("%%p = %-10p\n", "-123456");
	ft_printf("%% = %%\n");
}