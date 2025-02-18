
NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)
SRCS_AUX = $(wildcard aux/*.c)
SRCS_MOVES = $(wildcard moves/*.c)
SRCS_SORTS = $(wildcard sorts/*.c)
SRCS_SRC = ${wildcard src/*.c}
SRCS_ALL = $(SRCS) $(SRCS_AUX) $(SRCS_MOVES) $(SRCS_SORTS) ${SRCS_SRC}

OBJS = $(SRCS_ALL:.c=.o)

BONUS_AUX = $(wildcard bonus/aux/*.c)
BONUS_GNL = $(wildcard bonus/gnl/*.c)
BONUS_MOVES = $(wildcard bonus/moves/*.c)
BONUS_SRC = $(wildcard bonus/src/*.c)
BONUS_MAIN = $(wildcard bonus/*.c)

LIBGNL = bonus/gnl/libgnl.a

BONUS_ALL = $(BONUS_AUX) $(BONUS_GNL) $(BONUS_MOVES) $(BONUS_SRC) $(BONUS_MAIN)
BONUS_NAME = mychecker
BONUS_OBJS = $(BONUS_ALL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
		$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) -Lbonus/gnl -lgnl

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
