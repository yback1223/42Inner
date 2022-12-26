/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:08:46 by yback             #+#    #+#             */
/*   Updated: 2022/12/24 13:56:29 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    pa(t_stack *a, t_stack *b)
{
    push(b, a);
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack *a, t_stack *b)
{
    push(a, b);
    ft_putstr_fd("pb\n", 1);   
}

void    sa(t_stack *a)
{
    swap(a);
    ft_putstr_fd("sa\n", 1);
}

void    sb(t_stack *b)
{
    swap(b);
    ft_putstr_fd("sb\n", 1);
}

void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    ft_putstr_fd("ss\n", 1);
}

