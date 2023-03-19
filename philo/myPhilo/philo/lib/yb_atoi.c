/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yb_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:53:28 by yback             #+#    #+#             */
/*   Updated: 2023/03/18 19:03:39 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	yb_isspace(char space)
{
	if (space == 32 || space == 10 || (9 <= space && space <= 13))
		return (1);
	return (0);
}

int	yb_is_digit(char num)
{
	if ('0' <= num && num <= '9')
		return (1);
	return (0);
}

void	yb_is_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!yb_is_digit(str[i]))
			yb_error_handler();
}

int	yb_atoi(const char *str)
{
	long	sum;
	int		sign;
	int		i;

	sum = 0;
	sign = 1;
	i = 0;
	yb_is_valid((char *)str);
	while (yb_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (yb_is_digit(str[i]))
		sum += (sum * 10 + (str[i++]- 48));
	if ((sum * sign) > 2147483647 || ((sum * sign) < -2147483648))
		yb_error_handler();
	return (sum * sign);
}