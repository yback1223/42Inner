/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:24:08 by yback             #+#    #+#             */
/*   Updated: 2022/12/24 14:58:00 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    stack_index(t_stack *a)
{
    int i;
    int j;
    int *tmp;

    i = 0;
    tmp = (int *)malloc(sizeof(int) * a->length);
    if (tmp == NULL)
        print_error(1);
    while (i < a->length)
    {
        j = 0;
        tmp[i] = 0;
        while (j < a->length)
        {
            if (a->arr[i] > a->arr[j])
                tmp[i]++;
            j++;
        }
        i++;
    }
    free(a->arr);
    a->arr = NULL;
    a->arr = tmp;
}