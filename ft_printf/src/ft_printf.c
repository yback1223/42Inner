/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:13:38 by yback             #+#    #+#             */
/*   Updated: 2022/08/17 20:19:07 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_whichformat(va_list ap, char c)
{
	int	total_length;

	total_length = 0;
	if (c == 'c')
		total_length += ft_for_c(va_arg(ap, int));
	else if (c == 's')
		total_length += ft_for_s(va_arg(ap, char *));
	else if (c == 'p')
		total_length += ft_for_p(va_arg(ap, unsigned long long));
	else if (c == 'd' || c == 'i')
		total_length += ft_for_d(va_arg(ap, int));
	else if (c == 'u')
		total_length += ft_for_u(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		total_length += ft_for_xx(va_arg(ap, unsigned int), c);
	else if (c == '%')
		total_length +=	ft_for_percent();
	return (total_length);
}

int ft_printf(const char *arr, ...)
{
	va_list	ap;
	int		total_length;
	int		i;

	i = 0;
	total_length = 0;
	va_start(ap, arr);
	while (arr[i])
	{
		if (arr[i] == '%')
		{
			total_length += ft_whichformat(ap, arr[i + 1]);
			i++;
		}
		else
			total_length += ft_for_c(arr[i]);
		i++;
	}
	va_end(ap);
	return (total_length);
}

#include <stdio.h>
int main(void)
{
	int a = 0, b = 0;
	a = ft_printf("%X %x %%%c%d\n", -1, -1, 'c', 100);
	b = printf("%X %x %%%c%d\n", -1, -1, 'c', 100);

	printf("%d %d\n", a, b);
}