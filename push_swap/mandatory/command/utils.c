/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:03:30 by yback             #+#    #+#             */
/*   Updated: 2022/12/27 14:38:22 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->length - 1;
	tmp = get_top(stack);
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = get_bot(stack);
	while (i < stack->length - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->length - 1] = tmp;
}

void	push(t_stack *from_stack, t_stack *to_stack)
{
	int	tmp;

	tmp = get_top(from_stack);
	if (from_stack->length != 0)
	{
		from_stack->length--;
		to_stack->arr[to_stack->length] = tmp;
		to_stack->length++;
	}
}

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = get_top(stack);
	stack->arr[stack->length - 1] = stack->arr[stack->length - 2];
	stack->arr[stack->length - 2] = tmp;
}
