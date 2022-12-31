/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:43 by yback             #+#    #+#             */
/*   Updated: 2022/12/31 20:46:22 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		exit(1);
	init_stack(&a, 512);
	input_validator(&a, av);
	init_stack(&b, a.limit_length);
	check_command(&a, &b);
	print_result(&a, &b);
}

void	check_command(t_stack *a, t_stack *b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		command_bonus(a, b, command);
		free(command);
		command = 0;
		command = get_next_line(0);
	}
	free(command);
	command = 0;
}

void	command_bonus(t_stack *a, t_stack *b, char *command)
{
	if (compare_command(command, "sa\n") == 0)
		sa(a);
	else if (compare_command(command, "sb\n") == 0)
		sb(b);
	else if (compare_command(command, "ss\n") == 0)
		ss(a, b);
	else if (compare_command(command, "pa\n") == 0)
		pa(a, b);
	else if (compare_command(command, "pb\n") == 0)
		pb(a, b);
	else if (compare_command(command, "ra\n") == 0)
		ra(a);
	else if (compare_command(command, "rb\n") == 0)
		rb(b);
	else if (compare_command(command, "rr\n") == 0)
		rr(a, b);
	else if (compare_command(command, "rra\n") == 0)
		rra(a);
	else if (compare_command(command, "rrb\n") == 0)
		rrb(b);
	else if (compare_command(command, "rrr\n") == 0)
		rrr(a, b);
	else
		print_error(1);
}

void	print_result(t_stack *a, t_stack *b)
{
	if (b->length == 0 && already_sorted(a))
	{
		free(a->arr);
		free(b->arr);
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
	else
	{
		free(a->arr);
		free(b->arr);
		ft_putstr_fd("KO\n", 1);
		exit(1);
	}
}
