NAME = fillit


all:
	gcc -Wall -Wextra -Werror main.c libft/libft.a get_next_line.c
