/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:43 by yback             #+#    #+#             */
/*   Updated: 2022/12/28 20:53:16 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	command = get_command(0);
	while (command)
	{
		command_bonus(a, b, command);
		free(command);
		command = 0;
		command = get_command(0);
	}
	free(command);
	command = 0;
}

char	*get_command(int fd)
{
	char	*command;
	char	*result;

	command = get_next_line(fd);
	result = ft_strtrim(command, "\n");
	free(command);
	command = 0;
	return (result);
}

void	command_bonus(t_stack *a, t_stack *b, char *command)
{
	if (compare_command(command, "sa") == 0)
		sa(a);
	else if (compare_command(command, "sb") == 0)
		sb(b);
	else if (compare_command(command, "ss") == 0)
		ss(a, b);
	else if (compare_command(command, "pa") == 0)
		pa(a, b);
	else if (compare_command(command, "pb") == 0)
		pb(a, b);
	else if (compare_command(command, "ra") == 0)
		ra(a);
	else if (compare_command(command, "rb") == 0)
		rb(b);
	else if (compare_command(command, "rr") == 0)
		rr(a, b);
	else if (compare_command(command, "rra") == 0)
		rra(a);
	else if (compare_command(command, "rrb") == 0)
		rrb(b);
	else if (compare_command(command, "rrr") == 0)
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
