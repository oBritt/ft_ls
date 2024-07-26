CFLAGS = -Wall -Wextra -Werror 

SRCS = get_files.c get_files_h.c get_separator.c information_files.c information_files2.c information_files3.c \
information_files4.c main.c option_addition.c option_addition1.c option_cr.c sort.c start_ls.c start_ls_prints.c \
utils.c utils1.c utils2.c utils3.c utils4.c utils5.c validate_data_files.c validate_data_flags.c

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