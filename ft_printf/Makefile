# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 20:33:20 by yback             #+#    #+#              #
#    Updated: 2022/08/17 21:19:54 by yback            ###   ########.fr        #
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

SRC_FILES	= ft_for_cspitoa ft_for_duxxper ft_hex_and_dec ft_printf

SRC			= $(addprefix %(SRC_DIR), $(addprefix .c, $(SRC_FILES)))
OBJ			= $(addprefix %(OBJ_DIR), $(addprefix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					@$(AR) $(NAME) $(OBJ)
					@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
					@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF)			:	
					@mkdir -p $(OBJ_DIR)

clean			:
					@$(RM) -rf $(OBJ_DIR)
					@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean			:	clean
					@$(RM) -f $(NAME)
					@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"

re				:	fclean all
					@echo "$(Green)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY			:	all clean fclean re