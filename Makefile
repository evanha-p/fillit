NAME = fillit


all:
	make -C ./libft/
	gcc -o $(NAME) -Wall -Wextra -Werror test_main.c \
	libft/libft.a get_next_line.c utils.c reader.c \
	solver.c validator.c -g
clean:
	rm -f $(NAME)
	make fclean -C ./libft/
re: clean all

exec:
	./$(NAME) test
.PHONY: clean re all
