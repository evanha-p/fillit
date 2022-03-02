NAME = fillit


all:
	make -C ./libft/
	gcc -o $(NAME) -Wall -Wextra -Werror main3.c libft/libft.a get_next_line.c -g
clean:
	rm -f $(NAME)
re: clean all

exec:
	./$(NAME) test
.PHONY: clean re all
