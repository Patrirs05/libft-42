CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
SRCS = srcs/ft_*.c
NAME = libft.a
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re