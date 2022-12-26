/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:04:07 by yback             #+#    #+#             */
/*   Updated: 2022/12/24 13:56:58 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void print_error(int err)
{
    if (err == 1)
    {
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
    if (err == 2)
    {
        ft_putstr_fd("command error\n", 2);
        exit(1);
    }
}

int check_space(char c)
{
    if (c == '\t' || c == '\n' || c == '\v'
        || c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
}

void    free_str(char **str)
{
    int i;

    i = 0;
    while (str[i] != 0)
        free(str[i++]);
    free(str);
}