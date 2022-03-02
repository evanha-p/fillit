NAME = fillit


all:
	gcc -o $(NAME) -Wall -Wextra -Werror main.c \
	libft/libft.a get_next_line.c utils_list.c reader.c -g
	make -C ./libft/
clean:
	rm -f $(NAME)
re: clean all

exec:
	./$(NAME) test
.PHONY: clean re all
