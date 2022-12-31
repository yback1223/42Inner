/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:43:52 by yback             #+#    #+#             */
/*   Updated: 2022/12/27 14:39:51 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	length;
	int	limit_length;
}	t_stack;

/* command/etc.cc */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* command/reverse_rotate.c */
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* command/rotate.c */
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

/* command/utlis.c */
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *from_stack, t_stack *to_stack);
void	swap(t_stack *stack);

/* sort/sort.c */
void	sort_stack(t_stack *a, t_stack *b);
void	a_to_b(t_stack *a, t_stack *b, int formula, int i);
void	b_to_a(t_stack *a, t_stack *b);

/* sort/utils.c*/
int		get_top(t_stack *stack);
int		get_mid(t_stack *stack);
int		get_bot(t_stack *stack);
void	size_two_three_sort(t_stack *stack);
void	sort_b(t_stack *b, int length);

/* utils/array.c */
void	stack_index(t_stack *a);

/* utils/utils.c */
void	print_error(int err);
int		check_space(char c);
void	free_str(char **str);
int		compare_command(char *str1, char *str2);

/* utils/stack.c */
void	init_stack(t_stack *stack, int length);
void	insert_into_stack(t_stack *stack, int num);

/* validator/validator.c */
int		make_num(char *str);
void	input_validator(t_stack *stack, char *argv[]);
int		already_sorted(t_stack *stack);
void	check_dup(t_stack *stack);

/* checker.c */
void	check_command(t_stack *a, t_stack *b);
void	command_bonus(t_stack *a, t_stack *b, char *command);
void	print_result(t_stack *a, t_stack *b);

/* GNL */
int		ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *backup, char *tmp);
char	*making_backup(int fd, char *backup);
char	*making_newbackup(char *backup);
char	*making_ans(char *backup);
char	*get_next_line(int fd);

#endif
