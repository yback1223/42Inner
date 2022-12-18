/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:26:35 by yback             #+#    #+#             */
/*   Updated: 2022/08/25 21:01:38 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct t_info_s
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
	int		len;
	int		i;
	long	num;
	char	*s;
}	t_info;

char	*ft_wo_con(t_info *info, const char **fmt, va_list ap, char *wow);
char	*ft_w_con(t_info *info, const char **fmt, char *wow, va_list ap);
char	*ft_for_sc_mini(t_info *info, char *wow);
char	*ft_for_sc(t_info *info, const char **fmt, char *wow, va_list ap);
void	ft_for_flags(t_info *info, const char **fmt);
void	making_sign_and_spe(t_info *info, char *sign, int tmp);
char	*making_newarr(t_info *info, int *i);
char	*making_setting_one(t_info *info, int *i, char *wow);
char	*making_setting_two(t_info *info, char sign, char *wow, int tmp);
char	*making_setting_mini_one(t_info *info, char *wow);
char	*making_setting_three(t_info *info, char *wow, char sign, int tmp);
char	*making_setting_four(t_info *info, char *wow, char sign, int tmp);
char	*finish_part(t_info *info, int i, char *wow, char *newarr);
int		ft_atoi(const char **fmt);
int		ft_div(t_info *info);
int		ft_strnlen(char *s, int max);
void	init_info(t_info *info, const char **fmt);
char	*number(t_info *info, char *wow);
char	*ft_spec_intx(t_info *info, const char **fmt, va_list ap, char *wow);
int		ft_main_pri(char *buf, const char *fmt, va_list ap, t_info *info);
int		ft_printf(const char *fmt, ...);
int		ft_for_i(t_info *info, int i, char **newarr);
void	ft_for_small(t_info *info, const char fmt);

#endif