/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:32:35 by yback             #+#    #+#             */
/*   Updated: 2022/12/27 14:42:33 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	under_five_sort(t_stack *a, t_stack *b)
{
	while (a->length > 3)
	{
		while (get_top(a) >= get_mid(a))
			ra(a);
		pb(a, b);
	}
	if (a->length == 2 || a->length == 3)
		size_two_three_sort(a);
	while (b->length > 0)
		pa(a, b);
	if (get_top(a) > a->arr[a->length - 2])
		sa(a);
}

void	large_amount_sort(t_stack *a, t_stack *b)
{
	int	x;
	int	formula;

	x = a->length;
	formula = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	a_to_b(a, b, formula, 0);
	b_to_a(a, b);
}

void	a_to_b(t_stack *a, t_stack *b, int formula, int i)
{
	while (a->length != 0)
	{
		if (get_top(a) <= i)
		{
			pb(a, b);
			i++;
		}
		else if (i < get_top(a) && get_top(a) <= i + formula)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (get_top(a) > (i + formula))
		{
			if (i < a->length / 2 && i >= 0)
				rra(a);
			else
				ra(a);
		}
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	length;

	length = b->length - 1;
	while (b->length != 0)
	{
		sort_b(b, length--);
		pa(a, b);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->length <= 5)
		under_five_sort(a, b);
	else
		large_amount_sort(a, b);
}
