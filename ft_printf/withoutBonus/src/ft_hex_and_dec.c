/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_and_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:57:51 by yback             #+#    #+#             */
/*   Updated: 2022/08/18 11:10:29 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_len(long long num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	else if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_print_hex(uintptr_t address)
{
	if (address >= 16)
	{
		ft_print_hex(address / 16);
		ft_print_hex(address % 16);
	}
	else
	{
		if (address < 10)
			ft_for_c(address + '0');
		else
			ft_for_c(address - 10 + 'a');
	}
}

void	ft_print_hex2(unsigned int num, char xx)
{
	if (num >= 16)
	{
		ft_print_hex2(num / 16, xx);
		ft_print_hex2(num % 16, xx);
	}
	else
	{
		if (num < 10)
			ft_for_c(num + '0');
		else
		{
			if (xx == 'x')
				ft_for_c(num - 10 + 'a');
			else if (xx == 'X')
				ft_for_c(num - 10 + 'A');
		}
	}
}

int	ft_hex_len(uintptr_t address)
{
	int	i;

	i = 0;
	while (address)
	{
		address /= 16;
		i++;
	}
	return (i);
}

int	ft_hex_len2(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}
