NAME = pipex
CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
RM = rm -rf

SRCS = main.c\
       search_for_path.c\
       execute_help.c\
       libft/libft.a

$(NAME): all
        $(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)
        make -C libft

clean:
        $(RM) *.o
        make clean -C libft

fclean: clean
        $(RM) $(NAME)
        make fclean -C libft

re: fclean all

.PHONY: all clean fclean re libft
