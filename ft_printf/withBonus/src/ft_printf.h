/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:12:20 by yback             #+#    #+#             */
/*   Updated: 2022/08/18 11:12:20 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

int		ft_for_c(int c);
int		ft_for_s(char *str);
int		ft_for_p(unsigned long long address);
void	ft_itoa_print(long long num);
int		ft_for_d(int num);
int		ft_for_u(unsigned int num);
int		ft_for_xx(unsigned int num, char xx);
int		ft_for_percent(void);
int		ft_dec_len(long long num);
void	ft_print_hex(uintptr_t address);
void	ft_print_hex2(unsigned int num, char xx);
int		ft_hex_len(uintptr_t address);
int		ft_hex_len2(unsigned int num);
int		ft_whichformat(va_list ap, char c);
int		ft_printf(const char *arr, ...);

#endif