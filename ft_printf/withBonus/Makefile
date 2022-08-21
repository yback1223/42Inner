# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 20:33:20 by yback             #+#    #+#              #
#    Updated: 2022/08/20 20:10:13 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME	= libftprintf.a
INCLUDE	= include
SRC_DIR	= src/
OBJ_DIR = obj/
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I
RM		= rm -f
AR		= ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources

SRC_FILES	=	checkings cook_cspdixx cook_info ft_printf_util ft_printf

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					@$(AR) $(NAME) $(OBJ)
					@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"
					
$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean			:
					@$(RM) -rf $(OBJ_DIR)
					@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean			:	clean
					@$(RM) -f $(NAME)
					@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"

re				:	fclean all
					@echo "$(Green)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY			:	all clean fclean re
