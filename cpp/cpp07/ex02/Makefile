NAME = ex02
CFLAGS = -Wall -Wextra -Wextra -std=c++98

SRCS = main.cpp
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp
			@${CXX} ${CFLAGS} -c $< -o $@

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re