# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 10:23:59 by yback             #+#    #+#              #
#    Updated: 2023/02/09 09:35:16 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# SETUP
NAME		=	pipex
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

# HEADER
HEADER_SRCS	=	pipex.h pipex_bonus.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# FILES
MPATH_SRCS	=	main.c utils.c fd.c parse.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=	main_bonus.c utils_bonus.c fd_bonus.c parse_bonus.c
BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c ft_memset.c ft_strlen.c ft_putstr_fd.c
FUNC_DIR	=	libft/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))\
				gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_F		=	$(FUNC:.c=.o)

ifdef	BONUS_OPT
	OBJ_TOTAL = $(OBJ_B)
else
	OBJ_TOTAL = $(OBJ_M)
endif

#COMMANDS
%.o:			%.c $(HEADER)
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_TOTAL)
				@$(CC) $(OBJ_F) $(OBJ_TOTAL) -o $(NAME)

all:			$(NAME)

bonus:			
				@make BONUS_OPT=1 $(NAME)

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ_B)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean bonus re
