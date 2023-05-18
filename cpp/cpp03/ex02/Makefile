# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 15:57:53 by yback             #+#    #+#              #
#    Updated: 2023/05/17 17:08:34 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
CC = g++
CFLAGS = -Wall -Wextra -Wextra -std=c++98

SRCS = main.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re