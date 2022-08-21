/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:26:35 by yback             #+#    #+#             */
/*   Updated: 2022/08/21 15:20:43 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

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
int		ft_strnlen(char *str, int max);
int		ft_strchr(char *s, int c);
int		ft_div_mod(long *tmpnum, int base);

void	cook_di(info_t *info, va_list ap);
void	cook_xx(info_t *info, va_list ap);
void	cook_p(info_t *info, va_list ap);
void	cook_c(info_t *info, va_list ap);
void	cook_s(info_t *info, va_list ap);

char	checking_sign(info_t *info, long *num, int *size);
void	checking_special(info_t *info, int *size);
void	checking_num_second(info_t *info, int *size);
void	checking_num_first(info_t *info, long num, char sign, int *size);

void	cook_specifier(info_t *info, const char *fmt, int i, va_list ap);
int		ft_printf(const char *fmt, ...);

#endif