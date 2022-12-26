/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:02:54 by yback             #+#    #+#             */
/*   Updated: 2022/12/24 13:56:34 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    ra(t_stack *a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack *b)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1);
}

void    rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    ft_putstr_fd("rr\n", 1);
}