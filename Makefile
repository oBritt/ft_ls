CFLAGS = -Wall -Wextra -Werror 

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

NAME = ft_ls

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re