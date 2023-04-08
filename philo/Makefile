# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 20:03:04 by yback             #+#    #+#              #
#    Updated: 2023/04/08 19:15:35 by yback            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
RM = rm -f

NAME 		=	philo

SRCS		=	main.c \
				philo.c \
				init.c \
				utils.c \
				error.c \
				property.c \
				
OBJS		= $(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o			:	%.c
		$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean		:
		$(RM) $(OBJS)
		
fclean		:	clean
		$(RM) $(NAME)
		
re			:
		$(MAKE) fclean
		$(MAKE) all

.PHONY		:	all clean fclean re bonus
