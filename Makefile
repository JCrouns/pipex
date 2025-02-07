NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c execute_help.c search_for_path.c  \

all : libft
	$(CC) $(CGLAGS)  main.c execute_help.c search_for_path.c libft/libft.a

libft:
	$(MAKE) -C libft


clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
