# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:26:44 by yback             #+#    #+#              #
#    Updated: 2023/01/31 11:57:46 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS 	= srcs/pipex.c srcs/pipex_utils.c
OBJS 	= ${SRCS:.c=.o}

SRCS_B 	= srcs_bonus/pipex_bonus.c srcs_bonus/pipex_utils_bonus.c
OBJS_B 	= ${SRCS_B:.c=.o}
HEADER	= -I./includes

CC 		= @gcc
RM		= @rm -f
MAKE	= @make
CFLAGS	= -Werror -Wextra -Wall

ifdef	BONUS_OPT
	OBJ_TOTAL = $(OBJS_B)
else
	OBJ_TOTAL = $(OBJS)
endif

all: 		${NAME}

bonus:
			@make BONUS_OPT=1 $(NAME)

%.o: %.c $(HEADER)/*.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

${NAME}:	${OBJ_TOTAL}
			$(MAKE) re -C ./libft
			$(CC) ${OBJ_TOTAL} -Llibft -lft -o ${NAME}

clean:
			$(MAKE) clean -C ./libft
			$(RM) ${OBJS} ${OBJS_B}

fclean: 	clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY: all bonus clean fclean re