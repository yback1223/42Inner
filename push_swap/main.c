/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:57:01 by yback             #+#    #+#             */
/*   Updated: 2022/12/26 17:10:46 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
    init_stack(&a, 1024);
	input_validator(&a, argv);
	stack_index(&a);
	init_stack(&b, a.total);
	sort_stack(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}