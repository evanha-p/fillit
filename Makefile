NAME = fillit


all:
	make -C ./libft/
	gcc -o $(NAME) -Wall -Wextra -Werror main.c \
	libft/libft.a get_next_line.c utils.c reader.c -g
clean:
	rm -f $(NAME)
	make fclean -C ./libft/
re: clean all

exec:
	./$(NAME) test
.PHONY: clean re all
