# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 14:46:54 by yback             #+#    #+#              #
#    Updated: 2022/12/24 14:46:54 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT	=	mandatory/libft
LIBFT_A	=	mandatory/libft.a
BONUS	=	checker
RM = rm -rf
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	mandatory/command/etc.c\
		mandatory/command/reverse_rotate.c\
		mandatory/command/rotate.c\
		mandatory/command/utils.c\
		mandatory/sort/sort.c\
		mandatory/sort/utils.c\
		mandatory/utils/array.c\
		mandatory/utils/stacks.c\
		mandatory/utils/utils.c\
		mandatory/validator/validator.c\
		mandatory/main.c

SRCS_B =bonus/checker.c\
		bonus/command/etc.c\
		bonus/command/reverse_rotate.c\
		bonus/command/rotate.c\
		bonus/command/utils.c\
		bonus/sort/sort.c\
		bonus/sort/utils.c\
		bonus/utils/array.c\
		bonus/utils/stacks.c\
		bonus/utils/utils.c\
		bonus/validator/validator.c\
		bonus/gnl/get_next_line_utils.c\
		bonus/gnl/get_next_line.c
		
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
LIBC	= ar rc

ifdef WITH_BONUS
	NAME = $(BONUS)
	OBJECTS = $(OBJS_B)
	LIBFT	=	bonus/libft
	LIBFT_A	=	bonus/libft.a
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME):	$(OBJECTS)
			make all -C $(LIBFT)/
			$(CC) -o $(NAME) $(OBJECTS) -L $(LIBFT)	-lft

%.o	: %.c
			$(CC)	$(CFLAG) -c $^	-I./ -o $@

bonus	:
		make WITH_BONUS=1

clean	:
		$(RM) -f $(OBJS) $(OBJS_B)
		make clean -C mandatory/libft
		make clean -C bonus/libft

fclean	: clean
		$(RM) -f $(NAME)
		$(RM) -f mandatory/libft.a
		$(RM) -f bonus/libft.a
		$(RM) -f $(BONUS)
		make fclean -C mandatory/libft
		make fclean -C bonus/libft

re : fclean all

.PHONY : all clean fclean re bonus