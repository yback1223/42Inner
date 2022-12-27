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

typedef struct s_stack
{
	int	*arr;
	int	length;
	int	total;
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

/* utils/stack.c */
void	init_stack(t_stack *stack, int length);
void	insert_into_stack(t_stack *stack, int num);

/* utils/ft_memcpy.c */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/* utils/ft_putstr_fd.c */
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);

/* util/ft_split.c */
char	**ft_split(char const *s, char c);

/* validator/validator.c */
int		make_num(const char *str);
void	input_validator(t_stack *stack, char *argv[]);
int		already_sorted(t_stack *stack);
void	check_dup(t_stack *stack);

#endif