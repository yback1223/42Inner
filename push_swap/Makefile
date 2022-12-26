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
RM = rm -rf
CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = 	command/etc.c\
		command/reverse_rotate.c\
		command/rotate.c\
		command/utils.c\
		sort/sort.c\
		sort/utils.c\
		utils/array.c\
		utils/ft_memcpy.c\
		utils/ft_putstr_fd.c\
		utils/ft_split.c\
		utils/stacks.c\
		utils/utils.c\
		validator/validator.c\
		main.c

SRCS = $(OBJS)
SRCS_FILES = $(SRCS:c=o)

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^


all : $(NAME)

clean :
	$(RM) $(SRCS_FILES)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re