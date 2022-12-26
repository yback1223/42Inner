/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:08:35 by yback             #+#    #+#             */
/*   Updated: 2022/12/24 14:00:13 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void init_stack(t_stack *stack, int length)
{
    stack->arr = malloc(sizeof(int) * length);
    if (stack->arr == 0)
        print_error(1);
    stack->length = 0;
    stack->total = length;
}

void    insert_into_stack(t_stack *stack, int num)
{
    int *tmp;
    int index;
    
    index = stack->length;
    if (stack->length >= stack->total)
    {
        tmp = malloc(sizeof(int) * (stack->total * 2));
        if (tmp == 0)
            print_error(1);
        ft_memcpy(tmp, stack->arr, (stack->length * sizeof(int)));
        free(stack->arr);
        stack->arr = tmp;
        stack->total *= 2;
    }
    while (index > 0)
    {
        stack->arr[index] = stack->arr[index - 1];
        index--;
    }
    stack->arr[0] = num;
    stack->length++;
}