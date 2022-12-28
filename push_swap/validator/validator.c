/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:41:43 by yback             #+#    #+#             */
/*   Updated: 2022/12/27 16:05:08 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	input_validator(t_stack *stack, char *argv[])
{
	char	**tmp_arr;
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		tmp_arr = ft_split(argv[i++], ' ');
		if (tmp_arr == NULL)
			print_error(1);
		while (tmp_arr[j] != 0)
			insert_into_stack(stack, make_num(tmp_arr[j++]));
		free_str(tmp_arr);
	}
	check_dup(stack);
	if (already_sorted(stack) == 1)
		exit(1);
}

int	make_num(char *str)
{
	int			i;
	int			sign;
	int			num_check;
	long long	value;

	sign = 1;
	i = 0;
	num_check = 0;
	value = 0;
	while (check_space(*str))
		str++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i++] - '0');
		num_check++;
	}
	if (value * sign > 2147483647 || value * sign < -2147483648
		|| num_check == 0)
		print_error(1);
	return (value * sign);
}

void	check_dup(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < stack->length)
	{
		j = i + 1;
		tmp = stack->arr[i++];
		while (j < stack->length)
		{
			if (stack->arr[j] == tmp)
				print_error(1);
			j++;
		}
	}
}

int	already_sorted(t_stack *stack)
{
	int	i;
	int	length;

	i = 0;
	length = stack->length - 1;
	while (i < length)
	{
		if (stack->arr[i] < stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
