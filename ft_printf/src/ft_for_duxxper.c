/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_duxxper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:08:16 by yback             #+#    #+#             */
/*   Updated: 2022/08/17 20:15:57 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_for_d(int num)
{
	ft_itoa_print(num);
	return (ft_dec_len(num));
}

int	ft_for_u(unsigned int num)
{
	ft_itoa_print(num);
	return (ft_dec_len(num));
}

int	ft_for_xx(unsigned int num, char xx)
{
	ft_print_hex2(num, xx);
	return (ft_hex_len2(num));
}

int ft_for_percent()
{
	return (write(1, "%%", 1));
}