/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:21 by yback             #+#    #+#             */
/*   Updated: 2022/12/24 13:57:38 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    rra(t_stack *a)
{
    reverse_rotate(a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack *b)
{
    reverse_rotate(b);
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr_fd("rrr\n", 1);
}