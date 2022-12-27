/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:35:05 by yback             #+#    #+#             */
/*   Updated: 2022/12/27 14:45:05 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	get_top(t_stack *stack)
{
	return (stack->arr[stack->length - 1]);
}

int	get_mid(t_stack *stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < stack->length)
	{
		j = 0;
		k = 0;
		while (j < stack->length)
		{
			if (stack->arr[i] < stack->arr[j])
				k++;
			j++;
		}
		if (k == 2)
			return (stack->arr[i]);
		i++;
	}
	return (1);
}

int	get_bot(t_stack *stack)
{
	return (stack->arr[0]);
}

void	size_two_three_sort(t_stack *stack)
{
	if (already_sorted(stack))
		return ;
	if (stack->length == 2)
		sa(stack);
	else if (stack->arr[0] > stack->arr[2] && stack->arr[1] > stack->arr[0])
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->arr[2] > stack->arr[1] && stack->arr[0] > stack->arr[2])
		sa(stack);
	else if (stack->arr[2] > stack->arr[0] && stack->arr[1] > stack->arr[2])
		rra(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[2] > stack->arr[0])
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_b(t_stack *b, int length)
{
	int	i;

	i = 0;
	while (i < b->length && b->arr[i] != length)
		i++;
	while (0 <= i && i < b->length / 2)
	{
		rrb(b);
		i--;
	}
	while (b->length / 2 <= i && i < b->length - 1)
	{
		rb(b);
		i++;
	}
}
