CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

MANDATORY_SRCS = \
    ft_printf.c ft_helpers.c ft_helpers1.c


OBJS = $(MANDATORY_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
