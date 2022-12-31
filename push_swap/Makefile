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
LIBFT	=	libft
LIBFT_A	=	libft.a
BONUS	=	checker
RM = rm -rf
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	command/etc.c\
		command/reverse_rotate.c\
		command/rotate.c\
		command/utils.c\
		sort/sort.c\
		sort/utils.c\
		utils/array.c\
		utils/stacks.c\
		utils/utils.c\
		validator/validator.c\
		main.c

SRCS_B =checker.c\
		command/etc.c\
		command/reverse_rotate.c\
		command/rotate.c\
		command/utils.c\
		sort/sort.c\
		sort/utils.c\
		utils/array.c\
		utils/stacks.c\
		utils/utils.c\
		validator/validator.c\
		gnl/get_next_line_utils.c\
		gnl/get_next_line.c
		
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
LIBC	= ar rc

ifdef WITH_BONUS
	NAME = $(BONUS)
	OBJECTS = $(OBJS_B)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME):	$(OBJECTS)
			make all -C $(LIBFT)/
			$(CC) -o $(NAME) $(OBJECTS) -Llibft	-lft

%.o	: %.c
			$(CC)	$(CFLAG) -c $^	-I./ -o $@

bonus	:
		make WITH_BONUS=1

clean	:
		$(RM) -f $(OBJS) $(OBJS_B)
		make clean -C $(LIBFT)

fclean	: clean
		$(RM) -f $(NAME)
		$(RM) -f $(LIBFT_A)
		$(RM) -f $(BONUS)
		make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re bonus