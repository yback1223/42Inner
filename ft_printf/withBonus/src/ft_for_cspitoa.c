/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_cspitoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:07:02 by yback             #+#    #+#             */
/*   Updated: 2022/08/18 10:15:33 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_for_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_for_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i])
			write(1, &str[i++], 1);
	}
	return (i);
}

int	ft_for_p(unsigned long long address)
{
	int	total_length;

	total_length = 0;
	total_length += write(1, "0x", 2);
	if (address == 0)
		return (total_length + write(1, "0", 1));
	else
	{
		ft_print_hex(address);
		return (total_length + ft_hex_len(address));
	}
}

void	ft_itoa_print(long long num)
{
	if (num < 0)
	{
		ft_for_c('-');
		num *= -1;
	}
	if (num >= 10)
	{
		ft_itoa_print(num / 10);
		ft_itoa_print(num % 10);
	}
	else
		ft_for_c(num + '0');
}
