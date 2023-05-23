# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yback <yback@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 14:45:57 by yback             #+#    #+#              #
#    Updated: 2023/05/23 14:45:58 by yback            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal
CC = c++
CFLAGS = -Wall -Wextra -Wextra -std=c++98

SRCS = main.cpp Cat.cpp Dog.cpp Brain.cpp Animal.cpp WrongCat.cpp WrongAnimal.cpp
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