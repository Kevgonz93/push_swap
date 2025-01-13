
NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)
SRCS_AUX = $(wildcard aux/*.c)
SRCS_MOVES = $(wildcard moves/*.c)
SRCS_ALL = $(SRCS) $(SRCS_AUX) $(SRCS_MOVES)

OBJS = $(SRCS_ALL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
