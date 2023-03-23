CC = gcc
CFLAGS = -Wall -Wextra -Werror

MICRO1_SRC = micro_paint/micro_paint1.c
MICRO1_OBJ = $(MICRO1_SRC:.c=.o)
MICRO2_SRC = micro_paint/micro_paint2.c
MICRO2_OBJ = $(MICRO2_SRC:.c=.o)
MICRO3_SRC = micro_paint/test.c
MICRO3_OBJ = $(MICRO3_SRC:.c=.o)

MINI1_SRC = mini_paint/mini_paint1.c
MINI1_OBJ = $(MINI1_SRC:.c=.o)
MINI2_SRC = mini_paint/mini_paint2.c
MINI2_OBJ = $(MINI2_SRC:.c=.o)
MINI3_SRC = mini_paint/test.c
MINI3_OBJ = $(MINI3_SRC:.c=.o)

NAME = micro_paint1 micro_paint2 micro_paint3 mini_paint1 mini_paint2 mini_paint3

OBJS = $(MICRO1_OBJ) $(MICRO2_OBJ) $(MICRO3_OBJ) $(MINI1_OBJ) $(MINI2_OBJ) $(MINI3_OBJ)

all : $(NAME)

mini_paint1 : $(MINI1_OBJ)
	@$(CC) $(CFLAGS) -o $@ $<
mini_paint2 : $(MINI2_OBJ)
	@$(CC) $(CFLAGS) -o $@ $<
mini_paint3 : $(MINI3_OBJ)
	@$(CC) $(CFLAGS) -o $@ $<
micro_paint1 : $(MICRO1_OBJ)
	@$(CC) $(CFLAGS) -o $@ $<
micro_paint2 : $(MICRO2_OBJ)
	@$(CC) $(CFLAGS) -o $@ $<
micro_paint3 : $(MICRO3_OBJ)
	@$(CC) $(CFLAGS) -o $@ $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
