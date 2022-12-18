/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:58:05 by yback             #+#    #+#             */
/*   Updated: 2022/08/25 20:44:47 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct info_s
{
	int zeropad;
	int sign;
	int plus;
	int space;
	int left;
	int small;
	int special;
	int width;
	int precision;
	int precisionstat;
	char *str;
	int base;
	char fmt;
	int len;
	int i;
	long num;
	char *s;
} t_info;

int ft_atoi(const char **fmt)
{
	int i;

	i = 0;
	while (**fmt >= '0' && **fmt <= '9')
		i = i * 10 + *((*fmt)++) - '0';
	return (i);
}

int ft_div(t_info *info)
{
	int res;

	res = (unsigned long)info->num % (unsigned int)info->base;
	info->num = (unsigned long)info->num / (unsigned int)info->base;
	return (res);
}

int ft_strnlen(char *s, int max)
{
	int i;

	i = 0;
	if (max == 0)
		while (s[i])
			i++;
	else
		while (s[i] && i < max)
			i++;
	return (i);
}

void init_info(t_info *info, const char **fmt)
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
	info->len = 0;
	info->i = 0;
	info->num = 0;
	(*fmt)++;
}

void making_sign_and_spe(t_info *info, char *sign, int tmp)
{
	if (info->sign == 1)
	{
		if (info->num < 0)
		{
			*sign = '-';
			info->num *= -1;
			info->width--;
		}
		else if (info->plus == 1)
		{
			*sign = '+';
			info->width--;
		}
		else if (info->space == 1)
		{
			*sign = ' ';
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
}

char *making_newarr(t_info *info, int *i)
{
	char *newarr;

	newarr = (char *)malloc(100);
	if (info->num == 0)
	{
		if (info->precisionstat == 1)
			newarr[(*i)] = 0;
		else
			newarr[(*i)++] = '0';
	}
	else if (info->num == '%')
		newarr[(*i)++] = '%';
	else
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
	return (newarr);
}

char *making_setting_one(t_info *info, int *i, char *wow)
{
	if (*i > info->precision)
		info->precision = *i;
	info->width -= info->precision;
	if (info->zeropad != 1 && info->left != 1)
		while (info->width > 0)
		{
			*wow++ = ' ';
			info->width--;
		}
	return (wow);
}

char *making_setting_two(t_info *info, char sign, char *wow, int tmp)
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
	return (wow);
}

char *making_setting_mini_one(t_info *info, char *wow)
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
	return (wow);
}

char *making_setting_three(t_info *info, char *wow, char sign, int tmp)
{
	if (info->fmt == '%' && info->left != 1)
		wow = making_setting_mini_one(info, wow);
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
	return (wow);
}

char *making_setting_four(t_info *info, char *wow, char sign, int tmp)
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
	return (wow);
}

char *finish_part(t_info *info, int i, char *wow, char *newarr)
{
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
	free(newarr);
	return (wow);
}

char *number(t_info *info, char *wow)
{
	char sign;
	char *newarr;
	int i;
	long tmp;
	int tmpwidth;

	i = 0;
	tmp = info->num;
	tmpwidth = info->width;
	sign = 0;
	if (info->left == 1)
		info->zeropad = -1;
	if (info->base < 2 || info->base > 16)
		return (NULL);
	making_sign_and_spe(info, &sign, tmp);
	newarr = making_newarr(info, &i);
	wow = making_setting_one(info, &i, wow);
	if (info->left != 1 && info->zeropad == 1 && info->precisionstat == -1)
		wow = making_setting_two(info, sign, wow, tmp);
	else if (info->left != 1 && info->zeropad == 1 && tmpwidth > info->precision)
		wow = making_setting_three(info, wow, sign, tmp);
	else
		wow = making_setting_four(info, wow, sign, tmp);
	wow = finish_part(info, i, wow, newarr);
	return (wow);
}

char *ft_wo_con(t_info *info, const char *fmt, va_list ap, char *wow)
{
	if (*fmt == 'x')
	{
		info->small = 1;
		info->base = 16;
	}
	else if (*fmt == 'X')
		info->base = 16;
	else if (*fmt == 'd' || *fmt == 'i')
		info->sign = 1;
	if (info->sign == 1)
		info->num = va_arg(ap, int);
	else
		info->num = va_arg(ap, unsigned int);
	return (number(info, wow));
}

char *ft_w_con(t_info *info, const char **fmt, char *wow, va_list ap)
{
	if (**fmt == 'p')
	{
		info->small = 1;
		info->special = 1;
		info->base = 16;
		info->num = (unsigned long)va_arg(ap, void *);
		wow = number(info, wow);
	}
	else if (**fmt == '%')
	{
		info->num = '%';
		wow = number(info, wow);
	}
	else if (**fmt != 'u')
	{
		*wow++ = '%';
		if (**fmt)
			*wow++ = **fmt;
	}
	return (wow);
}

char *ft_for_sc_mini(t_info *info, char *wow)
{
	if (info->left == -1)
		while (info->len < info->width--)
			*wow++ = ' ';
	while (info->i++ < info->len)
		*wow++ = *info->s++;
	while (info->len < info->width--)
		*wow++ = ' ';
	return (wow);
}

char *ft_for_sc(t_info *info, const char **fmt, char *wow, va_list ap)
{
	if (**fmt == 'c')
	{
		if (info->left == -1)
			while (--info->width > 0)
				*wow++ = ' ';
		*wow++ = (unsigned char)va_arg(ap, int);
		while (--info->width > 0)
			*wow++ = ' ';
	}
	else if (**fmt == 's')
	{
		info->s = va_arg(ap, char *);
		if (info->s == 0)
			info->s = "(null)";
		if (info->precisionstat == 1 && info->precision == 0 && info->width == 0)
			return (0);
		else if (info->precisionstat != 1 || info->precision != 0)
			info->len = ft_strnlen(info->s, info->precision);
		wow = ft_for_sc_mini(info, wow);
	}
	return (wow);
}

void ft_for_flags(t_info *info, const char **fmt)
{
	while (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '#' || **fmt == '0')
	{
		if (**fmt == '-')
			info->left = 1;
		else if (**fmt == '+')
			info->plus = 1;
		else if (**fmt == ' ')
			info->space = 1;
		else if (**fmt == '#')
			info->special = 1;
		else if (**fmt == '0')
			info->zeropad = 1;
		(*fmt)++;
	}
	if (**fmt >= '0' && **fmt <= '9')
		info->width = ft_atoi(&(*fmt));
	if (**fmt == '.')
	{
		info->precisionstat = 1;
		(*fmt)++;
		if (**fmt >= '0' && **fmt <= '9')
			info->precision = ft_atoi(&(*fmt));
		if (info->precision < 0)
			info->precision = 0;
	}
	info->fmt = **fmt;
}

char *ft_for_specifiers(t_info *info, const char **fmt, va_list ap, char *wow)
{
	if (**fmt == 'c' || **fmt == 's')
		wow = ft_for_sc(info, &(*fmt), wow, ap);
	else if (**fmt == 'p' || **fmt == '%' || **fmt != 'u')
		wow = ft_w_con(info, &(*fmt), wow, ap);
	(*fmt)++;
	return (wow);
}

int ft_vsprintf(char *buf, const char *fmt, va_list ap, t_info *info)
{
	char *wow;

	wow = buf;
	while (*fmt)
	{
		if (*fmt != '%' && *fmt)
		{
			*wow++ = *fmt++;
			continue;
		}
		init_info(info, &fmt);
		ft_for_flags(info, &fmt);
		if (*fmt == 'x' || *fmt == 'X' || *fmt == 'd' || *fmt == 'i' || *fmt == 'u')
			wow = ft_wo_con(info, fmt, ap, wow);
		else
		{
			wow = ft_for_specifiers(info, &fmt, ap, wow);
			continue;
		}
		fmt++;
	}
	*wow = '\0';
	return (wow - buf);
}

int ft_printf(const char *fmt, ...)
{
	char arr[1000000];
	va_list ap;
	t_info info;
	int i;
	int j;

	j = 0;
	i = 0;
	va_start(ap, fmt);
	i = ft_vsprintf(arr, fmt, ap, &info);
	va_end(ap);
	while (j < i)
		write(1, &arr[j++], 1);
	return (i);
}

#include <stdio.h>

int main(void)
{
	printf("\\!/%052.42d\\!/", 0);
	printf("\n");
	ft_printf("\\!/%052.42d\\!/", 0);
	printf("\n");

}