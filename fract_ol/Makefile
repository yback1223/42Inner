# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 15:09:08 by yback             #+#    #+#              #
#    Updated: 2023/01/30 18:14:57 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
MLX_DIR = ./minilibx
MLX     = mlx
SRC		= srcs
CFLAGS	= -Werror -Wextra -Wall
MFLAGS  = -framework OpenGL -framework AppKit
CC		= cc
RM		= rm -f
FILES	= srcs/fractol.c srcs/julia_arg.c srcs/manage_mlx.c srcs/keycode_move.c srcs/keycode_zoom.c srcs/painter_fractals.c srcs/painter.c srcs/utils.c
OBJECTS	= $(FILES:.c=.o)
INCLUDE	= -I./include

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $@ $^ \
	-L$(MLX_DIR) -l$(MLX) $(MFLAGS)

$(SRC)/%.o: $(SRC)/%.c $(HEADER)/fractol.h $(HEADER)/keycodes.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

bonus: all

clean:
	$(RM) $(OBJECTS)
	make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
