# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:26:44 by yback             #+#    #+#              #
#    Updated: 2023/01/30 18:15:36 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS 	= srcs/pipex.c srcs/pipex_utils.c
OBJS 	= ${SRCS:.c=.o}
HEADER	= -I./includes

CC 		= gcc
CFLAGS	= -Werror -Wextra -Wall

all: 		${NAME}


%.o: %.c $(HEADER)/pipex.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

${NAME}:	${OBJS}
			make re -C ./libft
			$(CC) ${OBJS} -Llibft -lft -o ${NAME}

clean:
			make clean -C ./libft
			rm -f ${OBJS} 

fclean: 	clean
			make fclean -C ./libft
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re