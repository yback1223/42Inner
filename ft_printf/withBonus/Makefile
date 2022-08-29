# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 20:33:20 by yback             #+#    #+#              #
#    Updated: 2022/08/29 17:53:54 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME	= libftprintf.a
SRC_DIR	= src/
OBJ_DIR = obj/
SRC_BONUS_DIR	= src_bonus/
OBJ_BONUS_DIR = obj_bonus/
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm
AR		= ar rcs

# Sources

SRC_FILES		=	ft_for_cspitoa ft_for_duxxper ft_hex_and_dec ft_printf
SRC_BONUS_FILES	=	ft_printf ft_making_main_printf ft_making_number_one ft_making_number_two ft_printf_utils

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRC_BONUS 		= 	$(addprefix $(SRC_BONUS_DIR), $(addsuffix .c, $(SRC_BONUS_FILES)))
OBJ_BONUS		= 	$(addprefix $(OBJ_BONUS_DIR), $(addsuffix .o, $(SRC_BONUS_FILES)))

ifdef	BONUS_OPT
	OBJ_TOTAL = $(OBJ_BONUS)
	O_DIR = $(OBJ_BONUS_DIR)
	S_DIR = $(SRC_BONUS_DIR)
else
	OBJ_TOTAL = $(OBJ)
	O_DIR = $(OBJ_DIR)
	S_DIR = $(SRC_DIR)
endif

all				:	$(NAME)

bonus			:	
					@make BONUS_OPT=1 $(NAME)
					
$(NAME)			:	$(OBJ_TOTAL)
					@$(AR) $(NAME) $(OBJ_TOTAL)

$(O_DIR)%.o		:	$(S_DIR)%.c
					@mkdir -p $(O_DIR)
					@$(CC) $(CFLAGS) -c $< -o $@

clean			:
					@$(RM) -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean			:	clean
					@$(RM) -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
